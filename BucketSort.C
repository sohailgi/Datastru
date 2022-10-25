#include <stdio.h>
#include<limits.h> 
//Function to find maximum element of the array
int max_element(int arr[], int s) 
{  
    //Initializing max which is to be updated with any greater number encountered 
    int max = INT_MIN;  
    for (int i = 0; i < s; i++)
    {
        if (arr[i] > max)  
        max = arr[i];  
    }
    return max;  
}
 
//Implementing bucket sort 
void Bucket_Sort(int arr[], int s) 
{  
    int max = max_element(arr, s); 
    // Creating buckets 
    int bucket[max+1];  
 
    for (int i = 0; i <= max; i++)  
    bucket[i] = 0;  
 
    // Pushing elements in their corresponding buckets
    for (int i = 0; i < s; i++)  
    bucket[arr[i]]++;
 
    // Merging buckets effectively
    int j=0;   // j is a variable which points at the index we are updating
    for (int i = 0; i <= max; i++)  
    { 
        // Running while loop until there is an element in the bucket
        while (bucket[i] > 0)  
        {         
            arr[j++] = i;  
            bucket[i]--;   
        }  
    }  
}  
 
int main()
{
    int array[100], i, num; 
 
    printf("Enter the size of array: ");   
    scanf("%d", &num);   
    printf("Enter the %d elements to be sorted:\n",num); 
    for (i = 0; i < num; i++)
        scanf("%d", &array[i]); 
    printf("\nThe array of elements before sorting: \n");
    for (i = 0; i < num; i++)
        printf("%d ", array[i]);  
    printf("\nThe array of elements after sorting: \n"); 
 
    Bucket_Sort(array, num); 
    for (i = 0; i < num; i++)
        printf("%d ", array[i]);   
    printf("\n");     
    return 0;
}
