#include <stdio.h>
#include <stdlib.h>

int knapsackBT( int *w, int *v, int n, int wx, int i, int *x );

int main()
{
    int n = 5, wx = 11 ;
    int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
    int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
    int vx, *x ;
    x = new int[ n ] ;
    vx = knapsackBT( w, v, n, wx, 0, x ) ;
    printf( "Value = %d ,", vx ) ;
    for( int i = 0 ; i < n ; i++ ) printf( " %d", x[ i ] ) ;
    return 0 ;
}

/* ===================== Knapsack Problem - Backtracking ===================== */

static int g_bestValue = 0;
static int *g_bestX = NULL;
static int *g_currX = NULL;
static int g_n = 0;
static int *g_w = NULL;
static int *g_v = NULL;

static void copy_best()
{
    for (int k = 0; k < g_n; k++) g_bestX[k] = g_currX[k];
}

static int upper_bound_value(int start, int currValue)
{
    int bound = currValue;
    for (int k = start; k < g_n; k++) bound += g_v[k];
    return bound;
}

static void bt(int idx, int remainingW, int currValue)
{
    if (idx == g_n)
    {
        if (currValue > g_bestValue)
        {
            g_bestValue = currValue;
            copy_best();
        }
        return;
    }

    if (upper_bound_value(idx, currValue) <= g_bestValue) return;

    if (g_w[idx] <= remainingW)
    {
        g_currX[idx] = 1;
        bt(idx + 1, remainingW - g_w[idx], currValue + g_v[idx]);
    }

    g_currX[idx] = 0;
    bt(idx + 1, remainingW, currValue);
}

int knapsackBT( int *w, int *v, int n, int wx, int i, int *x )
{
    g_w = w;
    g_v = v;
    g_n = n;
    g_bestX = x;

    g_currX = (int*)malloc(sizeof(int) * n);
    if (g_currX == NULL) return 0;

    for (int k = 0; k < n; k++)
    {
        g_bestX[k] = 0;
        g_currX[k] = 0;
    }

    g_bestValue = 0;
    bt(i, wx, 0);

    free(g_currX);
    g_currX = NULL;

    return g_bestValue;
}
