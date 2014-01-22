#include <stdio.h>
#include <string.h>
#include "smallh.h"
#include "y.tab.h"
#include "common.h"

static int lbl;
int pc = 0;
char code[200][20];

void listcode(void)
{
	int i;
	for(i=0;i<pc;i++)
	{
		printf("%s",code[i]);
		fprintf(fOutput,"%s",code[i]);
	}
}

int wait = 0;
int assignment = 0;
char tempId[20];

int ex(nodeType* p)
{
	int lbl1,lbl2;
	if(!p) return 0;
	switch(p->type)
	{
	case typeCon:
		sprintf(code[pc++],"push %d\n",p->con.value);
		break;
	case typeId:
		sprintf(code[pc++],"push %s\n",p->id.name);
		break;
	case typeOpr:
		switch(p->opr.oper)
		{
		case IF:
			ex(p->opr.op[0]);
			if(p->opr.nops > 2) /* if else*/
			{
				sprintf(code[pc++],"jz L%03d\n",lbl1=lbl++);
				ex(p->opr.op[1]);
				sprintf(code[pc++],"jmp L%03d\n",lbl2=lbl++);
				sprintf(code[pc++],"L%03d:\n",lbl1);
				ex(p->opr.op[2]);
				sprintf(code[pc++],"L%03d:\n",lbl2);
			}
			else /* if */
            {
                sprintf(code[pc++],"jz L%03d\n",lbl1=lbl++);
				ex(p->opr.op[1]);
				sprintf(code[pc++],"L%03d:\n",lbl1);
            }
			break;
		case REPEAT:
			sprintf(code[pc++],"L%03d:\n",lbl1 = lbl++);
			ex(p->opr.op[0]);
			ex(p->opr.op[1]);
			sprintf(code[pc++],"jz L%03d\n",lbl1);
			sprintf(code[pc++],"L%03d:\n",lbl2 = lbl++);
			break;
		case WRITE:
			ex(p->opr.op[0]);
			sprintf(code[pc++],"out\n");
			break;
		case READ:
			ex(p->opr.op[0]);
			sprintf(code[pc++],"in %s\n",p->opr.op[0]->id.name);
			break;
		case WHILE:
			sprintf(code[pc++],"L%03d:\n",lbl1=lbl++);
			ex(p->opr.op[0]);
			sprintf(code[pc++],"jz L%03d\n",lbl2=lbl++);
			ex(p->opr.op[1]);
			sprintf(code[pc++],"jmp L%03d\n",lbl1);
			sprintf(code[pc++],"L%03d:\n",lbl2);
			break;
		case ASSIGN:
			if(p->opr.nops > 2) /* array */
			{
				sprintf(code[pc++],"push %s\n",p->opr.op[0]->id.name);
				ex(p->opr.op[1]);
				ex(p->opr.op[2]);
				sprintf(code[pc++],"stm %s\n",p->opr.op[0]->id.name);
			}
			else /* var */
			{
			    assignment = 1;
				ex(p->opr.op[1]);

				switch(wait)
				{
				case 0:
				    sprintf(code[pc++],"pop %s\n",p->opr.op[0]->id.name);
					break;
				case 1:
				    sprintf(code[pc++],"pop %s\n",p->opr.op[0]->id.name);
					sprintf(code[pc++],"push %s\n",tempId);
					sprintf(code[pc++],"inc\n");
					break;
				case 2:
				    sprintf(code[pc++],"pop %s\n",p->opr.op[0]->id.name);
					sprintf(code[pc++],"push %s\n",tempId);
					sprintf(code[pc++],"dec\n");
					break;
                case 3:
                    sprintf(code[pc++],"push %s\n",tempId);
                    sprintf(code[pc++],"pop %s\n",p->opr.op[0]->id.name);
                    break;
				}
				wait = 0;
				assignment = 0;
			}
			break;
		case VALUE:
			sprintf(code[pc++],"push %s\n",p->opr.op[0]->id.name);
			ex(p->opr.op[1]);
			sprintf(code[pc++],"ldm %s\n",p->opr.op[0]->id.name);
			break;
		case UMINUS:
            ex(p->opr.op[0]);
            sprintf(code[pc++],"neg\n");
            break;
		case '!':
			ex(p->opr.op[0]);
			sprintf(code[pc++],"not\n");
			break;
		case '~':
			ex(p->opr.op[0]);
			sprintf(code[pc++],"bitnot\n");
			break;
		case ODD:
			ex(p->opr.op[0]);
			sprintf(code[pc++],"odd\n");
			break;
		case ARRAY:
			sprintf(code[pc++],"new %s\n",p->opr.op[0]->id.name);
			sprintf(code[pc++],"alloc %d\n",p->opr.op[1]->con.value);
			break;
		case EXIT:
			sprintf(code[pc++],"halt\n");
			break;
		case BPP:
			sprintf(code[pc++],"push %s\n",p->opr.op[0]->id.name);
			strcpy(tempId,p->opr.op[0]->id.name);
			wait = 1;
			break;
		case BMM:
			sprintf(code[pc++],"push %s\n",p->opr.op[0]->id.name);
			strcpy(tempId,p->opr.op[0]->id.name);
			wait = 2;
			break;
		case FPP:
			sprintf(code[pc++],"push %s\n",p->opr.op[0]->id.name);
			strcpy(tempId,p->opr.op[0]->id.name);
			sprintf(code[pc++],"inc\n");
			wait = 3;
			break;
		case FMM:
			sprintf(code[pc++],"push %s\n",p->opr.op[0]->id.name);
            strcpy(tempId,p->opr.op[0]->id.name);
			sprintf(code[pc++],"dec\n");
			wait = 3;
			break;
        default:
            ex(p->opr.op[0]);
            ex(p->opr.op[1]);
            switch(p->opr.oper)
            {
            case '+':
                sprintf(code[pc++],"add\n");
                break;
            case '-':
                sprintf(code[pc++],"sub\n");
                break;
            case '*':
                sprintf(code[pc++],"mul\n");
                break;
            case '/':
                sprintf(code[pc++],"div\n");
                break;
			case '%':
				sprintf(code[pc++],"mod\n");
				break;
			case AND:
				sprintf(code[pc++],"and\n");
				break;
			case OR:
				sprintf(code[pc++],"or\n");
				break;
			case '^':
				sprintf(code[pc++],"bitxor\n");
            case '<':
                sprintf(code[pc++],"compLT\n");
                break;
            case '>':
                sprintf(code[pc++],"compGT\n");
                break;
            case GE:
                sprintf(code[pc++],"compGE\n");
                break;
            case LE:
                sprintf(code[pc++],"compLE\n");
                break;
            case EQ:
                sprintf(code[pc++],"compEQ\n");
                break;
            case NE:
                sprintf(code[pc++],"compNE\n");
                break;
			case '&':
				sprintf(code[pc++],"bitand\n");
				break;
			case '|':
				sprintf(code[pc++],"bitor\n");
				break;
            }
		}
	}
	switch(wait)
	{
    case 1:
        if(!assignment)
        {
            sprintf(code[pc++],"inc\n");
            wait = 0;
        }
        break;
    case 2:
        if(!assignment)
        {
            sprintf(code[pc++],"dec\n");
            wait = 0;
        }
        break;
    default:
        break;
	}
	return 0;
}

