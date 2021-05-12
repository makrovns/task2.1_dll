#include <gtest/gtest.h>
#include <cmath>
#include <windows.h> 
#include <stdio.h> 
#include "include_header.hpp"


TEST(mysin_test, for_ninety)
{
    Mysin_ptr mysin;
    HINSTANCE hinstlib;

    hinstlib = LoadLibrary(TEXT("mysin_dyn.dll"));
        
    if (hinstlib == NULL) 
    { 
        FAIL(); 
    }
    else 
    {
        mysin = (Mysin_ptr)GetProcAddress(hinstlib, "sin");

        double prom = 90 * PI / 180;

        ASSERT_NEAR(mysin(prom), sin(prom), 1e-4);
            
        FreeLibrary(hinstlib);
    }        
}

TEST(mysort_test, for_random_array)
{
    HINSTANCE hinstlib;
    Mysort_ptr mysort;

    hinstlib = LoadLibrary(TEXT("mysort_dyn.dll"));

    if(hinstlib == NULL)
    {
        FAIL();
    }
    else
    {
        mysort = (Mysort_ptr)GetProcAddress(hinstlib, "sorti");

        size_t n = 124;
        int* arr = new int[n];
        srand(time(0));

        for (int i = 0; i != n; ++i)
            arr[i] = rand() % 101 - 100;

        mysort(arr, n);

        for (int j = 1; j != n; ++j)
            ASSERT_LE(arr[j - 1], arr[j]);
        
        FreeLibrary(hinstlib);
    }
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}