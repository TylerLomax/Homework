#include <QCoreApplication>

void Swap(int* nl, int* n2){
int tmp = *nl;
*nl = *n2;
*n2 = tmp;
}

void fill_array_with_rand_num(int* array, int Size){
for (int i = 0; i < Size; ++i){
array[i] = rand() & 100000;
srand (time (NULL));
}
}

void BubbleSort(int* array, int Size){
for (int i = 0; i < Size - 1; i++)
for (int j = 0; j < Size - i - 1; j++)
if (array[j] > array[i + 1])
Swap(&array[j], &array[j + 1]);
}

void InsertionSort(int* array, int Size){
for (int i = 1; i < Size; i++)
for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
Swap(&array[j - 1], &array[j]);
}
void SelectionSort(int* array, int Size){
for (int i = 0; i < Size - 1; ++i){
int smallestIndex = i;
for (int j= i + 1; j < Size; ++j) {
if (array[j] < array[smallestIndex])
smallestIndex = j;
}
Swap(&array[i], &array[smallestIndex]);
}
}


void ShellSort(int* array, int Size){
for (int gap = Size / 2; gap > 0; gap /= 2){
for (int i = gap; i < Size; i += 1)
{
int temp = array[i];
int j;
for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
array[j] = array[j - gap];
array[j] = temp;
}
}
}
void QuickSort(int* array, int Size){
int lenD = Size;
int pivot = 0;
int ind = lenD / 2;
int i, j = 0, k = 0;
if (lenD >1){
int* L = new int[lenD];
int* R = new int[lenD];
pivot = array[ind];
for (i = 0; i < lenD; i++)
{
if (i != ind){
if (array[i] < pivot){
L[j] = array[i];
++j;
}
else{
R[k] = array[i],
++k;
}
}
}


QuickSort (L, j);
QuickSort (R, k);
for (int cnt = 0;cnt < lenD; ++cnt){
if (cnt < j){
array[cnt] = L[cnt];
}
else if (cnt == j){
array[cnt] = pivot;
}
else
{
array[cnt]= R[cnt - (j + 1)];
}
}
delete [] L;
delete [] R;

}
}

void Merge(int* merged, int* L, int lenL, int* R, int lenR) {
int i = 0;
int j = 0;
while (i < lenL || j < lenR)
{
if (i < lenL && j < lenR){

if (L[i] <= R[j]) {
merged[i + j] = L[i];
++i;
}
else {
merged[i + j] = R[j];
++j;}
}
else if (i < lenL) {
merged[i + j] = L[i];
++i;
}
else if (j < lenR) {
merged[i + j] = R[i];
++j;
}
}
}

void MergeSort(int* array, int Size){

if (Size > 1){


int middle = Size / 2;
int rem = Size - middle;
int* L = new int[middle];
int* R = new int[rem];
for (int i = 0; i < Size; ++i){
if ( i < middle)
L[i] = array[i];
else
R[i - middle] = array[i];
}
MergeSort(L, middle);
MergeSort(R, rem);
Merge(array, L, middle, R, rem);
delete [] L;
delete [] R;
}
}

