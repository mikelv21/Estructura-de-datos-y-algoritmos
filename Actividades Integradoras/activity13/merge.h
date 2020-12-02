// =================================================================
//
// File: insertion.h
// Author: Pedro Perez, José Miguel Luna Vega A01706424
// Description: This file contains the implementation of the
//				merge sort, sorting months and days of a date
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef MERGE_H
#define MERGE_H

#include <iostream>
#include <vector>
#include <cstring>
#include "header.h"
#include "registro.h"

using namespace std;

// =================================================================
// Copy the range [low, high] from array B to array A.
//
// @param A, the destination array.
// @param B, the source array.
// @param low, lower index.
// @param high, higher index.
// =================================================================
void copyArray(vector<Registro> &A, vector<Registro> &B, int low, int high) {

	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

// =================================================================
// Merge both halves of A, using B array as temporary storage.
//
// @param A, the source array.
// @param B, the destination array.
// @param low, lower index.
// @param mid, middle index.
// @param high, higher index.
// =================================================================
void merge (vector<Registro> &A, vector<Registro> &B, int low, int mid, int high) {
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high){
        if(A[i].get_fecha() < A[j].get_fecha()) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    for(; j <= high; j++){
        B[k++] = A[j];
    }

	  for(; i <= mid; i++){
        B[k++] = A[i];
    }
}

// =================================================================
// If the minimum unit has not been reached (a single array
// position), separate the range [low, high] into two halves,
// invoking the split process again. When no more separations can be
// made, mix both halves of the arrangement.
//
// @param A, the source array.
// @param B, the temporal array.
// @param low, lower index.
// @param high, higher index.
// =================================================================

void split(vector<Registro> &A, vector<Registro> &B, int low, int high) {
    int  mid;

		if (high - low == 0) return;

    mid = low + ((high - low) / 2);
    split(A, B, low, mid);
    split(A, B, mid + 1, high);
    merge(A, B,low, mid, high);
    copyArray(A, B, low, high);
}

// =================================================================
// Performs the merge sort algorithm.
//
// @param A, an array of T elements.
// @param size, the number of elements in the array.
// =================================================================

void mergeSort(vector<Registro> &A) {
	vector<Registro> B(A.size());
	split(A, B, 0, A.size() - 1);
}


#endif /* MERGE_H */
