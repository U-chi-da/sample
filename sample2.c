#include <stdio.h>
#define MAX_SIZE 100

struct seiseki {
    char name[20]; /* 名前 */
    int  jpn;      /* 国語 */
    int  math;     /* 数学 */
    int  eng;      /* 英語 */

    int  sum;
};

void swap_seiseki(struct seiseki *a, struct seiseki *b)
{
    struct seiseki temp = *a;
    *a = *b;
    *b = temp;
}

void sort_jpn(struct seiseki a[], int size)
{
    int i, j, max;
    for(j = 0; j < size-1; j++){
        max = j;
        for(i = j+1; i < size; i++){
            if(a[i].jpn > a[max].jpn) max = i;
        }
        swap_seiseki(&a[j], &a[max]);
    }
}

void sort_math(struct seiseki a[], int size)
{
    int i, j, max;
    for(j = 0; j < size-1; j++){
        max = j;
        for(i = j+1; i < size; i++){
            if(a[i].math > a[max].math) max = i;
        }
        swap_seiseki(&a[j], &a[max]);
    }
}

void sort_eng(struct seiseki a[], int size)
{
    int i, j, max;
    for(j = 0; j < size-1; j++){
        max = j;
        for(i = j+1; i < size; i++){
            if(a[i].eng > a[max].eng) max = i;
        }
        swap_seiseki(&a[j], &a[max]);
    }
}

void sort_sum(struct seiseki a[], int size)
{
    int i, j, max;
    for(j = 0; j < size-1; j++){
        max = j;
        for(i = j+1; i < size; i++){
            if(a[i].sum > a[max].sum) max = i;
        }
        swap_seiseki(&a[j], &a[max]);
    }
}

void put_seiseki(struct seiseki a[], int size)
{
    int i;

    printf("名前                  国  数  英   計\n");
    for (i = 0; i < size; i++) {
        printf("%-20s %3d %3d %3d  %3d\n", a[i].name, a[i].jpn, a[i].math, a[i].eng, a[i].sum);
    }
}

void sum_seiseki(struct seiseki a[], int size)
{
    int i;
    for(i = 0; i < size; i++){
        a[i].sum = a[i].jpn + a[i].math + a[i].eng;
    }   
}

int main(void)
{
    struct seiseki array[] =
        {{"Sato",   81, 34, 67, 0},
         {"Sanaka", 72, 94, 88, 0},
         {"Takao",  60, 78, 62, 0},
         {"Mike",   96, 89, 93, 0},
         {"Masaki", 58, 46, 81, 0}};

    int horw, size = 5;

    sum_seiseki(array, size);
    
    printf("1) 国語, 2) 数学, 3) 英語, 4) 合計: ");
    scanf("%d", &horw);

    if(horw == 1)
        sort_jpn(array, size);

    if(horw == 2)
        sort_math(array, size);

    if(horw == 3)
        sort_eng(array, size);

    if(horw == 4)
        sort_sum(array, size);

    

    put_seiseki(array, size);

    return 0;
}
