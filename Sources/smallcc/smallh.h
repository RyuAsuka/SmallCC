typedef enum{typeCon, typeId, typeOpr} nodeEnum;

/* Constants */
typedef struct
{
    int value;
}conNodeType;

/* identifiers */
typedef struct
{
	char* name;
}idNodeType;

/* operators */
typedef struct
{
    int oper; /* operator */
    int nops; /* number of oprands */
    struct nodeTypeTag *op[1]; /* operands(expandable) */
}oprNodeType;

typedef struct nodeTypeTag
{
    nodeEnum type; /* type of node */
    /* union must be last entry in nodeType */
    /* because operNodeType may dynamically increase */
    union
    {
        conNodeType con;
        idNodeType id;
        oprNodeType opr;
    };
}nodeType;
