#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

node    *new_node(node n) //! NO TOCAR
{
    node *ret = calloc(1, sizeof(n));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n) //!NO TOCAR
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n"); //! CAMBIAR FILE POR INPUT
}

int accept(char **s, char c)
{
    if (**s == c) //? AÑADIMOS '== C'
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}

//? AÑADO LAS SIGUIENTES FUNCIONES
node	*add(char **s);
node	*multi(char **s);
node	*val(char **s);

node	*add(char **s)
{
	(void)s;
	return (NULL);
}

node	*multi(char **s)
{
	(void)s;
	return (NULL);
}

node	*val(char **s)
{
	node	*ret = NULL;

	if (isdigit(**s))
	{
		ret = new_node((node){.type = VAL, .val = **s - '0'});
		(*s)++;
		return (ret);
	}
	if (accept(s, '('))
	{
		ret = add(s);
		if (!ret || !expect(s, ')'))
		{
			destroy_tree(ret);
			return (NULL);
		}
	}
	unexpected(**s);
	return (NULL);
}

node    *parse_expr(char *s) //!TOCAMOS ESTA FUNCION
{
    node	*ret = add(&s); //? AÑADIMOS

    if (ret && *s) //? AÑADIMOS RET
    {
		unexpected(*s); //? AÑADIMOS
        destroy_tree(ret);
        return (NULL);
    }
    return (ret);
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
	return (0); //! AÑADIMOS ESTA LINEA
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    node *tree = val(&argv[1]);
    if (!tree)
        return (1);
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
	return (0); //! AÑADIMOS EL RETURN
}