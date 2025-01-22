import streamlit as st
from collections import defaultdict, Counter


# Function to build the De-Bruijn graph
def build_debruijn_graph(reads, k):
    graph = defaultdict(list)
    edge_weights = defaultdict(Counter)
    for read in reads:
        for i in range(len(read) - k + 1):
            kmer1 = read[i:i + k - 1]
            kmer2 = read[i + 1:i + k]
            graph[kmer1].append(kmer2)
            edge_weights[kmer1][kmer2] += 1
    return graph, edge_weights


# Function to construct genome using Eulerian path with edge weights
def construct_genome(graph, edge_weights):
    # Calculate in-degree and out-degree
    in_degree, out_degree = defaultdict(int), defaultdict(int)
    for node, edges in graph.items():
        out_degree[node] += len(edges)
        for edge in edges:
            in_degree[edge] += 1

    # Find the start node for the Eulerian path
    start_node = None
    for node in graph:
        if out_degree[node] > in_degree[node]:
            start_node = node
            break
    if not start_node:
        start_node = next(iter(graph))

    # Traverse the graph to construct the genome
    path = []
    stack = [start_node]
    while stack:
        node = stack[-1]
        if graph[node]:
            # Choose the most frequent edge
            next_node = max(graph[node], key=lambda x: edge_weights[node][x])
            graph[node].remove(next_node)
            stack.append(next_node)
        else:
            path.append(stack.pop())
    path.reverse()

    # Construct genome from the path
    genome = path[0]
    for node in path[1:]:
        genome += node[-1]
    return genome


# Function to compute accuracy
def compute_accuracy(draft_genome, key_genome):
    matches = sum(1 for a, b in zip(draft_genome, key_genome) if a == b)
    accuracy = matches / len(key_genome) * 100
    return accuracy


# Streamlit application
def main():
    st.set_page_config(page_title="Genome Assembly", page_icon="🧬", layout="wide")
    st.title("🧬 Genome Assembly with De-Bruijn Graph")

    # Sidebar inputs
    st.sidebar.header("🔧 Inputs")
    key_genome = st.sidebar.text_area(
        "Key Genome",
        value="""
acctcggcaacatccgatcatcatatgatcaattatgactcatcccgcgtggaattatgtagccaatgaaatcgctccatatttcaaaaattgagttttcacagtggccgcaatctataaagccgcgagcgaagcgagcggtaggcattttcagtttgaccaaaatgcctagcaacgcaacaaccaaccgagcccgtgggtggtgcttcaccctgaacaacccacccccagagatgatatcagagaggcgagtggttgtccctggccatgtcagtggacttgacgcagccattcccactgaacccaatctaccagaacacagacactgtgactaccgtgtgggtcaactggagagaggtgacaacggcacccctgaacaacccacccccagagatgatatagtgatgaagtcc
""",
        height=200,
    )

    reads = st.sidebar.text_area(
        "Reads (one per line)",
        value="""
acctcggcaa
ggcaacatcc
catccgatca
gatcatcata
tcatatgatc
tgatcaatta
aattatgact
tgactcatcc
catcccgcgt
cgcgtggaat
ggaattatgt
tatgtagcca
""",
        height=200,
    ).strip().split("\n")

    k = st.sidebar.slider("K-mer size", min_value=5, max_value=15, value=10)

    if st.sidebar.button("🧬 Assemble Genome"):
        # Build De-Bruijn graph
        st.markdown("### Building the De-Bruijn Graph...")
        graph, edge_weights = build_debruijn_graph(reads, k)

        # Construct draft genome
        st.markdown("### Constructing the Draft Genome...")
        draft_genome = construct_genome(graph, edge_weights)

        # Calculate accuracy
        st.markdown("### Computing Accuracy...")
        accuracy = compute_accuracy(draft_genome, key_genome.strip())

        # Display results
        st.success("Draft Genome Constructed Successfully!")
        st.text_area("Constructed Draft Genome", value=draft_genome, height=200)
        st.write(f"Accuracy: {accuracy:.2f}%")

        # Display graph info
        st.subheader("De-Bruijn Graph")
        st.json({node: edges for node, edges in graph.items() if edges})


if __name__ == "__main__":
    main()
