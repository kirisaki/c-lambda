#include<stdio.h>

typedef enum {
    Var,
    Lam,
    App
} expr_type;

typedef struct expr {
    expr_type type;
    union payload{
        struct {
            char symbol;
        };
        struct {
            char variable;
            struct expr *expr;
        };
        struct {
            struct expr *applyer;
            struct expr *aplyee;
        };
    };
} expr_t;



int main(){
    printf("%d\n", sizeof(expr_t));
}
