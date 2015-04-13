#ifndef THOMPSON_H
#define THOMPSON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct State State;
struct State
{
  int c;
  State *out;
  State *out1;
  int lastlist;
};

/*
 * A partially built NFA without the matching state filled in.
 * Frag.start points at the start state.
 * Frag.out is a list of places that need to be set to the
 * next state for this fragment.
 */
typedef struct Frag Frag;
typedef union Ptrlist Ptrlist;
struct Frag
{
  State *start;
  Ptrlist *out;
};

/*
 * Since the out pointers in the list are always 
 * uninitialized, we use the pointers themselves
 * as storage for the Ptrlists.
 */
union Ptrlist
{
  Ptrlist *next;
  State *s;
};

typedef struct List List;
struct List
{
  State **s;
  int n;
};
List l1, l2;
static int listid;

/*
 * Represents a DFA state: a cached NFA state list.
 */
typedef struct DState DState;
struct DState
{
  List l;
  DState *next[256];
  DState *left;
  DState *right;
};

char*
re2post(char *re);

State*
state(int c, State *out, State *out1);

Frag
frag(State *start, Ptrlist *out);

int nstate;

Ptrlist*
list1(State **outp);
void
patch(Ptrlist *l, State *s);
Ptrlist*
append(Ptrlist *l1, Ptrlist *l2);
State*
post2nfa(char *postfix);

List*
startlist(State *start, List *l);
int
ismatch(List *l);
void
addstate(List *l, State *s);

void
step(List *clist, int c, List *nlist);
static int
listcmp(List *l1, List *l2);
static int
ptrcmp(const void *a, const void *b);
DState*
dstate(List *l);
void
startnfa(State *start, List *l);
DState*
startdstate(State *start, List *l1);

DState*
nextstate(DState *d, int c, List *l1);
int
match(DState *start, char *s, List *l1);

#endif