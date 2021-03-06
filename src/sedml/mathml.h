/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
#ifndef SEDML_MATHML_H
#define SEDML_MATHML_H

#include <sedml/common.h>

SEDML_C_DECL_BEGIN

#define SEDML_MATHML_NAMESPACE "http://www.w3.org/1998/Math/MathML"

#define SEDML_MATHML_FUNCTION_DEFINITION_URL(name) (SEDML_NAMESPACE "#" #name)

enum sedml_mathml_type {
	/* token */
	SEDML_MATHML_CN,
	SEDML_MATHML_CI,
	SEDML_MATHML_CSYMBOL,
	SEDML_MATHML_SEP,
	/* general */
	SEDML_MATHML_APPLY,
	SEDML_MATHML_PIECEWISE,
	SEDML_MATHML_PIECE,
	SEDML_MATHML_OTHERWISE,
	SEDML_MATHML_LAMBDA,
	/* relational operators */
	SEDML_MATHML_EQ,
	SEDML_MATHML_NEQ,
	SEDML_MATHML_GT,
	SEDML_MATHML_LT,
	SEDML_MATHML_GEQ,
	SEDML_MATHML_LEQ,
	/* arithmetic operators */
	SEDML_MATHML_PLUS,
	SEDML_MATHML_MINUS,
	SEDML_MATHML_TIMES,
	SEDML_MATHML_DIVIDE,
	SEDML_MATHML_POWER,
	SEDML_MATHML_ROOT,
	SEDML_MATHML_ABS,
	SEDML_MATHML_EXP,
	SEDML_MATHML_LN,
	SEDML_MATHML_LOG,
	SEDML_MATHML_FLOOR,
	SEDML_MATHML_CEILING,
	SEDML_MATHML_FACTORIAL,
	/* logical operators */
	SEDML_MATHML_AND,
	SEDML_MATHML_OR,
	SEDML_MATHML_XOR,
	SEDML_MATHML_NOT,
	/* quantifiers */
	SEDML_MATHML_DEGREE,
	SEDML_MATHML_BVAR,
	SEDML_MATHML_LOGBASE,
	/* trigonometric operators */
	SEDML_MATHML_SIN,
	SEDML_MATHML_COS,
	SEDML_MATHML_TAN,
	SEDML_MATHML_SEC,
	SEDML_MATHML_CSC,
	SEDML_MATHML_COT,
	SEDML_MATHML_SINH,
	SEDML_MATHML_COSH,
	SEDML_MATHML_TANH,
	SEDML_MATHML_SECH,
	SEDML_MATHML_CSCH,
	SEDML_MATHML_COTH,
	SEDML_MATHML_ARCSIN,
	SEDML_MATHML_ARCCOS,
	SEDML_MATHML_ARCTAN,
	SEDML_MATHML_ARCSEC,
	SEDML_MATHML_ARCCSC,
	SEDML_MATHML_ARCCOT,
	SEDML_MATHML_ARCSINH,
	SEDML_MATHML_ARCCOSH,
	SEDML_MATHML_ARCTANH,
	SEDML_MATHML_ARCSECH,
	SEDML_MATHML_ARCCSCH,
	SEDML_MATHML_ARCCOTH,
	/* constants */
	SEDML_MATHML_TRUE,
	SEDML_MATHML_FALSE,
	SEDML_MATHML_NOTANUMBER,
	SEDML_MATHML_PI,
	SEDML_MATHML_INFINITY,
	SEDML_MATHML_EXPONENTIALE,
	/* MathML annotations */
	SEDML_MATHML_SEMANTICS,
	SEDML_MATHML_ANNOTATION,
	SEDML_MATHML_ANNOTATION_XML,
	/* function */
	SEDML_MATHML_MIN,
	SEDML_MATHML_MAX,
	SEDML_MATHML_SUM,
	SEDML_MATHML_PRODUCT
};

#define SEDML_MATHML_ELEMENT \
	enum sedml_mathml_type type

struct sedml_mathml_element {
	SEDML_MATHML_ELEMENT;
};

struct sedml_mathml_token {
	SEDML_MATHML_ELEMENT;
	char *body;
};

struct sedml_mathml_node {
	SEDML_MATHML_ELEMENT;
	int num_children;
	struct sedml_mathml_element **children;
};

#define SEDML_MATHML_IS_TYPE_TOKEN(type) ((type) <= SEDML_MATHML_SEP)

#define SEDML_MATHML_IS_TOKEN(e) SEDML_MATHML_IS_TYPE_TOKEN((e)->type)

SEDML_FUNCTION struct sedml_mathml_element *sedml_create_mathml_element(const char *name);

SEDML_FUNCTION int sedml_mathml_node_add_child(struct sedml_mathml_node *,
					       struct sedml_mathml_element *);

SEDML_FUNCTION void sedml_destroy_mathml_element(struct sedml_mathml_element *);

SEDML_FUNCTION int sedml_mathml_element_compare(const struct sedml_mathml_element *,
						const struct sedml_mathml_element *);

SEDML_FUNCTION const char *
               sedml_mathml_element_name(const struct sedml_mathml_element *);

SEDML_C_DECL_END

#endif
