# genome_assembly.py

from collections import defaultdict, deque

class DeBruijnGraph:
    def __init__(self, k):
        self.k = k
        self.graph = defaultdict(list)  # Adjacency list
        self.in_degree = defaultdict(int)
        self.out_degree = defaultdict(int)
    
    def add_edge(self, kmer):
        prefix = kmer[:-1]
        suffix = kmer[1:]
        self.graph[prefix].append(suffix)
        self.out_degree[prefix] += 1
        self.in_degree[suffix] += 1
    
    def build_graph(self, reads):
        for read in reads:
            if len(read) != self.k:
                continue  # Skip reads that don't match the expected k-mer size
            self.add_edge(read)
    
    def find_start_node(self):
        start = None
        for node in self.graph:
            out_deg = self.out_degree[node]
            in_deg = self.in_degree[node]
            if out_deg > in_deg:
                start = node
                break
        if not start:
            start = next(iter(self.graph))
        return start
    
    def eulerian_path(self):
        graph = {node: deque(neighbors) for node, neighbors in self.graph.items()}
        path = []
        stack = []
        current = self.find_start_node()
        
        while stack or graph.get(current):
            if not graph.get(current):
                path.append(current)
                current = stack.pop()
            else:
                stack.append(current)
                next_node = graph[current].popleft()
                current = next_node
        path.append(current)
        return path[::-1]

def reconstruct_genome(path, k):
    """
    Reconstructs the genome from the Eulerian path.
    """
    if not path:
        return ""
    genome = path[0]
    for node in path[1:]:
        genome += node[-1]
    return genome

def assess_accuracy(draft, key_genome):
    """
    Compares the draft genome with the key genome and returns accuracy metrics.
    """
    matches = sum(1 for a, b in zip(draft, key_genome) if a == b)
    total = min(len(draft), len(key_genome))
    accuracy = (matches / total) * 100 if total > 0 else 0
    return accuracy, matches, total

def parse_fasta(fasta_str):
    """
    Parses a FASTA formatted string and returns the concatenated sequence.
    """
    lines = fasta_str.strip().split('\n')
    sequence = ''.join(line.strip() for line in lines if not line.startswith('>'))
    return sequence

def parse_reads(reads_str):
    """
    Parses the list of reads from a given string.
    """
    reads = [line.strip() for line in reads_str.strip().split('\n') if line.strip()]
    return reads

def assemble_genome(key_genome_str, reads_str, k=10):
    """
    Main function to assemble the genome and assess accuracy.
    """
    key_genome = parse_fasta(key_genome_str)
    reads = parse_reads(reads_str)
    
    dbg = DeBruijnGraph(k)
    dbg.build_graph(reads)
    
    path = dbg.eulerian_path()
    draft_genome = reconstruct_genome(path, k)
    
    accuracy, matches, total = assess_accuracy(draft_genome, key_genome)
    
    return {
        "draft_genome": draft_genome,
        "accuracy": accuracy,
        "matches": matches,
        "total": total
    }
