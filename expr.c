#include "expr.h"
#include "stdlib.h"
#include "stdio.h"


struct Expr *mk_plus(struct Expr *e1, struct Expr *e2) {
    struct Expr *ret = malloc(sizeof(struct Expr));
    ret->type = PLUS;
    ret->subexprs.e1 = e1;
    ret->subexprs.e2 = e2;

    return ret;
}

struct Expr *mk_minus(struct Expr *e1, struct Expr *e2) {
    struct Expr *ret = malloc(sizeof(struct Expr));
    ret->type = MINUS;
    ret->subexprs.e1 = e1;
    ret->subexprs.e2 = e2;

    return ret;
}

struct Expr *mk_times(struct Expr *e1, struct Expr *e2) {
    struct Expr *ret =  malloc(sizeof(struct Expr));
    ret->type = TIMES;
    ret->subexprs.e1 = e1;
    ret->subexprs.e2 = e2;

    return ret;
}

struct Expr *mk_div(struct Expr *e1, struct Expr *e2) {
    struct Expr *ret = malloc(sizeof(struct Expr));
    ret->type = DIV;
    ret->subexprs.e1 = e1;
    ret->subexprs.e2 = e2;

    return ret;
}

struct Expr *mk_float(float f) {
    struct Expr *ret = malloc(sizeof(struct Expr));
    ret->type = FLOAT;
    ret->literal = f;

    return ret;
}

/* This function should create the expr (1 + (4 * 5))
 * using the above constructors.
 */
struct Expr *mk_expr1() {
  struct Expr *num1 = mk_float(1.0);
    struct Expr *num4 = mk_float(4.0);
    struct Expr *num5 = mk_float(5.0);
    struct Expr *mul = mk_times(num4, num5);
    return mk_plus(num1, mul);
}

/* This function should create the expr (1 + (7 / 8))
 * using the above constructors.
 */
struct Expr *mk_expr2() {
    struct Expr *num1 = mk_float(1.0);
    struct Expr *num4 = mk_float(7.0);
    struct Expr *num5 = mk_float(8.0);
    struct Expr *div = mk_div(num7, num8);
    return mk_plus(num1, div);
}

/* This function should create the expr ((1 / 3) - (4 / (2 + 3)))
 * using the above constructors.
 */
struct Expr *mk_expr3() {
    struct Expr *mk_expr3() {
    struct Expr *num1 = mk_float(1.0);
    struct Expr *num3 = mk_float(3.0);
    struct Expr *div1 = mk_div(num1, num3);

    struct Expr *num4 = mk_float(4.0);
    struct Expr *num2 = mk_float(2.0);
    struct Expr *num5 = mk_float(5.0);
    struct Expr *add = mk_plus(num2, num5);
    struct Expr *div2 = mk_div(num4, add);

    return mk_minus(div1, div2);
}


/*
 * This function should free all memory associated 
 * with the given AST.
*/
void free_expr(struct Expr* e) {
    if (e == NULL) return;

    if (e->type != FLOAT) {  // If it's an operation, free subexpressions
        free_expr(e->subexprs.e1);
        free_expr(e->subexprs.e2);
    }

    free(e); // Free the current node

}

/*
 * This function should evaluate the given AST and
 * return the floating-point result.
*/
float eval(struct Expr* e) {
  if (e->type == FLOAT) {
        return e->literal;  // Return the stored float value
    }

    // Recursively evaluate subexpressions
    float left = eval(e->subexprs.e1);
    float right = eval(e->subexprs.e2);

    // Perform the appropriate operation
    switch (e->type) {
        case PLUS: return left + right;
        case MINUS: return left - right;
        case TIMES: return left * right;
        case DIV: return left / right;
        default: return 0.0;
    }
}




