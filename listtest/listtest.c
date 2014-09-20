#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define MAXLINE 1000

char *readline(FILE *rfile) {
  /* Read a line from a file and return a new line string object */
  char buf[MAXLINE];
  int len;
  char *result = NULL;
  char *line = fgets(buf, MAXLINE, rfile);
  if (line) {
    len = strnlen(buf, MAXLINE);
    result = strncpy(malloc(len+1),buf,len+1);
  }
  return result;
}

struct line {
  struct list_elem elem;
  char *lineptr;
};

bool line_less_fun (const struct list_elem *a,
		    const struct list_elem *b,
		    void *aux) {
  return (strcmp(list_entry (a, struct line, elem)->lineptr,
		 list_entry (b, struct line, elem)->lineptr) < 0);
}

int main (int argc, char *argv[])
{
  FILE *rfile;
  char *l;
  struct line *lp;
  int i;

  struct list line_list;
  struct list_elem *e;

  if (argc < 2) {
    fprintf(stderr,"Usage %s filename",argv[0]);
    exit(0);
  }

  rfile = fopen((char *) argv[1], "r");
  if (!rfile) {
    printf("error opening %s\n",argv[0]);
    exit(0);
  } 

  list_init (&line_list);	/* generic list object */
  if (list_empty(&line_list)) printf("Empty list\n");

  for (i = 0; (l = readline(rfile)); i++) {
    lp = (struct line *) malloc(sizeof(struct line));
    lp->lineptr = l;
    //    printf("Insert: %s", l);
    list_push_back(&line_list, &lp->elem);
  }  
  printf("List size: %ld\n", list_size(&line_list));

  i = 0;
  for (e = list_begin( &line_list); e != list_end(&line_list);
       e = list_next(e)) {
    lp = list_entry (e, struct line, elem);
    printf("%d: %s",i,lp->lineptr);
    i++;
  }

  list_sort(&line_list, line_less_fun, NULL);

  i = 0;
  for (e = list_begin( &line_list); e != list_end(&line_list);
       e = list_next(e)) {
    lp = list_entry (e, struct line, elem);
    printf("%d: %s",i,lp->lineptr);
    i++;
  }

  exit(0);
  return 0;
}
