 
 String S=input1;
 int op=input2;
 int N = S.length();
        boolean isFlipped = false; // Track if the string is flipped (operation 1)
        int halfSwapCount = 0;     // Track how many type 2 swaps are needed

        // Process the operations
        for (int i=0;i<input2;i++) {
            op=input3[i];
            if (op == 1) {
                isFlipped = !isFlipped; // Toggle the flip status
            } else if (op == 2) {
                halfSwapCount++;        // Increment half swap count
            }
        }

        // Convert the string to a mutable character array
        char[] chars = S.toCharArray();

        // If the string is flipped, swap the first and last characters once
        if (isFlipped) {
            char temp = chars[0];
            chars[0] = chars[N - 1];
            chars[N - 1] = temp;
        }

        // If the halfSwapCount is odd, perform the swap of first N/2 with last N/2
        if (halfSwapCount % 2 == 1) {
            for (int i = 0; i < N / 2; i++) {
                char temp = chars[i];
                chars[i] = chars[N / 2 + i];
                chars[N / 2 + i] = temp;
            }
        }

        // Return the final string as a result
        return new String(chars);