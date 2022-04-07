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
    e->type = Var;
    e->payload.symbol = c;
    return e;
}

expr *lam(char c, expr *e){
    expr *e0 = malloc(sizeof(expr));
    e0->type = Lam;
    e0->payload.variable = c;
    e0->payload.expr = e;
    return e0;
}

expr *app(expr *er, expr *ee){
    expr *e = malloc(sizeof(expr));
    e->type = App;
    e->payload.applyer = er;
    e->payload.applyee = ee;
    return e;
}

void show(expr *e){
    switch (e->type)
    {
    case Var:
        printf("(Var '%c')", e->payload.symbol);
        break;
    case Lam:
        printf("(Lam '%c' ", e->payload.variable);
        show(e->payload.expr);
        printf(")");
        break;
    case App:
        printf("(App ");
        show(e->payload.applyer);
        printf(" ");
        show(e->payload.applyee);
        printf(")");
        break;
    default:
        break;
    }
}

int main(){
    show(app(lam('x', var('x')), var('y')));
    printf("\n");
}
