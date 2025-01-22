# app.py

import streamlit as st
from genome_assembly import assemble_genome, parse_fasta, parse_reads
import textwrap

def main():
    st.title("Genome Assembly Tool")
    st.write("""
    ### Assemble a draft genome from overlapping reads using the De Bruijn Graph approach.
    
    **Instructions:**
    1. Provide the **Key Genome** in FASTA format.
    2. Provide the **List of Reads** (each read on a new line).
    3. Click on **Assemble Genome** to perform the assembly.
    4. View the results below and download the draft genome.
    """)

    st.sidebar.header("Input Options")
    input_method = st.sidebar.selectbox("Choose Input Method", ("Text Input", "Upload Files"))

    if input_method == "Text Input":
        key_genome_input = st.text_area(
            "Enter Key Genome (FASTA format):",
            value=""">Genome
acctcggcaacatccgatcatcatatgatcaattatgactcatcccgcgtggaattatgtagccaatgaaatcgctccatatttcaaaaattgagttttcacagtggccgcaatctataaagccgcgagcgaagcgagcggtaggcattttcagtttgaccaaaatgcctagcaacgcaacaaccaaccgagcccgtgggtggtgcttcaccctgaacaacccacccccagagatgatatcagagaggcgagtggttgtccctggccatgtcagtggacttgacgcagccattcccactgaacccaatctaccagaacacagacactgtgactaccgtgtgggtcaactggagagaggtgacaacggcacccctgaacaacccacccccagagatgatatagtgatgaagtcc"""
        )
        reads_input = st.text_area(
            "Enter List of Reads (one read per line):",
            value="""acctcggcaa
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
agccaatgaa
atgaaatcgc
atcgctccat
tccatatttc
atttcaaaaa
aaaaattgag
ttgagttttc
ttttcacagt
acagtggccg
ggccgcaatc
caatctataa
tataaagccg
agccgcgagc
cgagcgaagc
gaagcgagcg
gagcggtagg
gtaggcattt
cattttcagt
tcagtttgac
ttgaccaaaa
caaaatgcct
tgcctagcaa
agcaacgcaa
cgcaacaacc
caaccaaccg
aaccgagccc
agcccgtggg
agccaatgaa
atgaaatcgc
atcgctccat
tccatatttc
atttcaaaaa
aaaaattgag
ttgagttttc
ttttcacagt
acagtggccg
ggccgcaatc
caatctataa
tataaagccg
agccgcgagc
cgagcgaagc
gaagcgagcg
gagcggtagg
gtaggcattt
cattttcagt
tcagtttgac
ttgaccaaaa
caaaatgcct
tgcctagcaa
agcaacgcaa
cgcaacaacc
caaccaaccg
aaccgagccc
agcccgtggg  
gtgggtggtg
tggtgcttca
cttcaccctg
ccctgaacaa
aacaacccac
cccaccccca
ccccagagat
gagatgatat
gatatcagag
cagagaggcg
aggcgagtgg
agtggttgtc
ttgtccctgg
cctggccatg
ccatgtcagt
tcagtggact
ggacttgacg
tgacgcagcc
cagccattcc
attcccactg
cactgaaccc
aacccaatct
aatctaccag
accagaacac
aacacagaca
agacactgtg
ctgtgactac
actaccgtgt
cgtgtgggtc
gggtcaactg
aactggagag
gagagaggtg
aggtgacaac
acaacggcac
ggcacccctg
ccctgaacaa
aacaacccac
cccaccccca
ccccagagat
gagatgatat
gatatagtga
agtgatgaag
gatgaagtcc
gtgggtggtg
tggtgcttca
cttcaccctg
ccctgaacaa
aacaacccac
cccaccccca
ccccagagat
gagatgatat
gatatcagag
cagagaggcg
aggcgagtgg
agtggttgtc
ttgtccctgg
cctggccatg
ccatgtcagt
tcagtggact
ggacttgacg
tgacgcagcc
cagccattcc
attcccactg
cactgaaccc
aacccaatct
aatctaccag
accagaacac
aacacagaca
agacactgtg
ctgtgactac
actaccgtgt
cgtgtgggtc
gggtcaactg
aactggagag
gagagaggtg
aggtgacaac
acaacggcac
ggcacccctg
ccctgaacaa
aacaacccac
cccaccccca
ccccagagat
gagatgatat
gatatagtga
agtgatgaag
gatgaagtcc"""
        )
    else:
        key_genome_file = st.file_uploader("Upload Key Genome File (FASTA format):", type=["fasta", "fa"])
        reads_file = st.file_uploader("Upload Reads File (one read per line):", type=["txt"])
        key_genome_input = key_genome_file.read().decode("utf-8") if key_genome_file else ""
        reads_input = reads_file.read().decode("utf-8") if reads_file else ""

    k = st.sidebar.number_input("k-mer size (default=10)", min_value=1, max_value=100, value=10, step=1)

    if st.button("Assemble Genome"):
        if not key_genome_input.strip():
            st.error("Please provide the Key Genome.")
            return
        if not reads_input.strip():
            st.error("Please provide the list of Reads.")
            return
        if len(key_genome_input.strip().split('\n')) < 2:
            st.error("Key Genome FASTA format is incorrect. Ensure it has a header and sequence.")
            return

        with st.spinner("Assembling genome..."):
            results = assemble_genome(key_genome_input, reads_input, k=k)
        
        st.success("Genome assembly completed!")
        
        # Display Results
        st.subheader("Assembly Results")
        st.write(f"**Draft Genome Length:** {len(results['draft_genome'])}")
        st.write(f"**Accuracy:** {results['accuracy']:.2f}% ({results['matches']}/{results['total']})")
        
        # Display Draft Genome (with line breaks for readability)
        st.subheader("Draft Genome Sequence")
        wrapped_genome = '\n'.join(textwrap.wrap(results['draft_genome'], 60))
        st.text_area("Draft Genome:", wrapped_genome, height=300)

        # Download Draft Genome as FASTA
        st.subheader("Download Draft Genome")
        draft_fasta = ">Draft_Genome\n" + '\n'.join(textwrap.wrap(results['draft_genome'], 60))
        st.download_button(
            label="Download Draft Genome as FASTA",
            data=draft_fasta,
            file_name="draft_genome.fasta",
            mime="text/plain"
        )

if __name__ == "__main__":
    main()
