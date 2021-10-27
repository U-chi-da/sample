#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

struct student{
    int id;
    char name[MAX_SIZE];
};
typedef struct student Student;

/* 二つのポインタ引数で示される Student型の値を入れかえる */
void swap_student(Student *a, Student *b)
{
    Student temp = *a;
    *a = *b;
    *b = temp;
}

/* 長さ size のStudent型配列 a[] の各要素を
   選択ソートでid順（昇順）に並べかえる */
void ssort_id(Student a[], int size)
{
    int i, j, min;
    for(j = 0; j < size-1; j++){
        min = j;
        for(i = j+1; i < size; i++){
            if(a[i].id < a[min].id) min = i;
        }
        swap_student(&a[j], &a[min]);
    }
}

/* 長さ size のStudent型配列 a[] の各要素を
   選択ソートで名前順（昇順）に並べかえる */
void ssort_name(Student a[], int size)
{
    int i, j, min;
    for(j = 0; j < size-1; j++){
        min = j;
        for(i = j+1; i < size; i++){
            if((strcmp(a[i].name, a[min].name)) < 0) min = i;
        }
        swap_student(&a[j], &a[min]);
    }
}

/* 配列 a[] のメンバ id に探索鍵(ID) x があるかどうかを二分探索で判定する */
int bsearch_id(Student a[], int p, int q, int x)
{
    int t = (p + q) / 2;
    if(p > q){
        return -1;
    }
    if(a[t].id == x){
        return t;
    }
    if(a[t].id > x){
        q = t - 1;
    }else{
        p = t + 1;
    }
    return bsearch_id(a, p, q, x);
}

/* 配列 a[] のメンバ name に探索鍵(名前) x があるかどうかを二分探索で判定する */
int bsearch_name(Student a[], int p, int q, char *x)
{
    int t = (p + q) / 2;
    if(p > q){
        return -1;
    }
    if((strcmp(a[t].name, x)) == 0){
        return t;
    }
    if((strcmp(a[t].name, x)) > 0){
        q = t - 1;
    }else{
        p = t + 1;
    }
    return bsearch_name(a, p, q, x);
}

/* 長さ size の配列 a[] の各要素にユーザからの入力値を格納する */
void get_students(Student a[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        printf("a[%d]\n", i);
        printf("  ID  : ");  scanf("%d", &a[i].id);
        printf("  名前: ");  scanf("%s", a[i].name);
    }
}

/* 長さ size の配列 a[] を表示する */
void put_students(Student a[], int size)
{
    int i;

    printf("\n要素  ID  名前\n");
    for (i = 0; i < size; i++) {
        printf("a[%d]: %2d  %-15s\n", i, a[i].id, a[i].name);
    }
}

int main(void)
{
    int size, pos, key, horw;
    char keystr[MAX_SIZE];
    Student a[MAX_SIZE];

    printf("データ数: ");  scanf("%d", &size);
    get_students(a, size);
    printf("1) ID, 2) 名前: ");
    scanf("%d", &horw);

    switch (horw) {
    case 1:
        ssort_id(a, size); /* ID番号で昇順に並べ替え */
        put_students(a, size);
        printf("探索鍵(ID): ");  scanf("%d", &key);
        pos = bsearch_id(a, 0, size-1, key);
        if (pos >= 0) {
            printf("探索鍵(ID) %d, 名前 %s が a[%d] に見つかりました\n", key, a[pos].name, pos);
        } else {
            printf("探索鍵(ID) %d は見つかりませんでした\n", key);
        }
        break;
    case 2:
        ssort_name(a, size);/* 名前で昇順に並べ替え */
        put_students(a, size);
        printf("探索鍵(名前): ");  scanf("%s", keystr);
        pos = bsearch_name(a, 0, size-1, keystr);
        if (pos >= 0) {
            printf("探索鍵(名前) %s, ID %d が a[%d] に見つかりました\n", keystr, a[pos].id, pos);
        } else {
            printf("探索鍵(名前) %s は見つかりませんでした\n", keystr);
        }
        break;
    }

    return 0;
}
