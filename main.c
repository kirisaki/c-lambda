#include<stdio.h>
#include<stdlib.h>

typedef enum {
    Var,
    Lam,
    App
} expr_type;

typedef struct expr_t {
    expr_type type;
    union payload_t{
        struct {
            char symbol;
        };
        struct {
            char variable;
            struct expr_t *expr;
        };
        struct {
            struct expr_t *applyer;
            struct expr_t *applyee;
        };
    } payload;
} expr;

expr *var(char c){
    expr *e = malloc(sizeof(expr));
    e->payload.symbol = c;
    return e;
}

expr *lam(char c, expr *e){
    expr *e0 = malloc(sizeof(expr));
    e0->payload.variable = c;
    e0->payload.expr = e;
    return e0;
}

expr *app(expr *er, expr *ee){
    expr *e = malloc(sizeof(expr));
    e->payload.applyer = er;
    e->payload.applyee = ee;
    return e;
}

int main(){
    printf("%ld\n", sizeof(expr));
}
