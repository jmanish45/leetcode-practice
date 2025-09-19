class Solution {
public:
    // Function to calculate the amount of trapped rainwater
    int trap(vector<int>& height) {
        int n = height.size();  // Get the size of the height array

        // Initialize the 'prev' array to store the maximum height encountered from the left
        int prev[n];
        prev[0] = -1;  // Set the first value of 'prev' to -1 since there's no left boundary for the first element
        
        int max = height[0];  // 'max' will store the highest height encountered so far from the left
        for(int i = 1; i < n; i++) {  
            prev[i] = max;  // Store the maximum height encountered until index i-1
            if(max < height[i])  // If the current height is greater than the max height so far
                max = height[i];  // Update 'max' to the current height
        }

        // Initialize the 'next' array to store the maximum height encountered from the right
        int next[n];
        next[n - 1] = -1;  // Set the last value of 'next' to -1 since there's no right boundary for the last element
        
        max = height[n - 1];  // 'max' will store the highest height encountered so far from the right
        for(int i = n - 2; i >= 0; i--) {  // Traverse the heights from right to left
            next[i] = max;  // Store the maximum height encountered from index i+1 to the end
            if(max < height[i])  // If the current height is greater than the max height so far
                max = height[i];  // Update 'max' to the current height
        }

        // Now, we update the 'prev' array to store the minimum of the left and right max heights
        // This represents the maximum possible height at each position considering both directions
        for(int i = 0; i < n; i++) {
            prev[i] = min(prev[i], next[i]);  // Store the minimum of the left max (prev[i]) and right max (next[i])
        }

        int water = 0;  // Variable to accumulate the total amount of trapped water
        // Loop through each element except the first and last (since they cannot trap any water)
        for(int i = 1; i < n - 1; i++) {
            // Check if the current height is less than the minimum of the left and right max heights
            if(height[i] < prev[i]) {
                water += (prev[i] - height[i]);  // The trapped water is the difference between the minimum height and current height
            }
        }

        return water;  // Return the total amount of trapped water
    }
};
