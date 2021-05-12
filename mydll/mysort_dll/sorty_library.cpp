#include "sorty_library.h"

namespace{
    void rewriteArray(int* array, int* array_intermediate, size_t array_size)
    {
        for (size_t i = 0; i != array_size; ++i) 
        {
            array[i] = array_intermediate[i];
        }
    }
        
    void writeIntermediate(int* array, int* array_intermediate, size_t* left_index, size_t* right_index, size_t* index_Intermediate)
    {
        if (array[*left_index] > array[*right_index]) {
             array_intermediate[(*index_Intermediate)++] = array[(*right_index)++];
        }
        else {
            array_intermediate[(*index_Intermediate)++] = array[(*left_index)++];
        }
    }

    void iteration(int* array, int* array_intermediate, size_t array_size, size_t iteration_size)
    {
        size_t right_position = iteration_size;
        size_t left_index = 0, right_index = right_position, index_Intermediate = 0;
        size_t counter = iteration_size;
            
         while (counter < array_size)  {
            if (left_index == (array_size - 1))
                array_intermediate[left_index] = array[left_index];
                
            while ((((left_index < right_position) || (right_index < (right_position + iteration_size))) && (right_index < array_size))) {
                writeIntermediate(array, array_intermediate, &left_index, &right_index, &index_Intermediate);
                    
                if (left_index == right_position) {
                    while ((right_index != (right_position + iteration_size)) && (right_index != array_size)) {
                        array_intermediate[index_Intermediate++] = array[right_index++];
                    }
                }
                    
                if ((right_index == (right_position + iteration_size)) || (right_index == array_size)) {
                    while (left_index != right_position) {
                        array_intermediate[index_Intermediate++] = array[left_index++];
                    }
                }
            }
                
            left_index += iteration_size;
            right_index += iteration_size;
            right_position = left_index + iteration_size;
            ++counter;
        }  
    }
    
}
    
void mysort::sorti(int* array, size_t array_size) 
{
    if (array_size < 2)
        return;
        
    int* array_intermediate = new int[array_size];
    size_t iteration_size = 1;
        
    while (iteration_size < array_size) {
        iteration(array, array_intermediate, array_size, iteration_size);

        rewriteArray(array, array_intermediate, array_size);
            
        iteration_size *= 2;
    }
        
    delete[] array_intermediate;
}