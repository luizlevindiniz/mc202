#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dequef.h"

/**
   Create an empty deque of floats.

   capacity is both the initial and minimum capacity.
   factor is the resizing factor, larger than 1.0.

   On success it returns the address of a new dequef.
   On failure it returns NULL.
**/
dequef *df_alloc(long capacity, double factor)
{
   dequef *deque = malloc(sizeof(dequef));
   if (deque)
   {

      deque->cap = capacity;
      deque->mincap = capacity;
      deque->factor = factor;
      deque->size = 0;
      deque->first = 0;
      deque->data = malloc(sizeof(float) * capacity);
      return deque;
   }
   else
   {
      return NULL;
   }
}

/**
  Release a dequef and its data.
**/
void df_free(dequef *D)
{

   free(D->data);
   free(D);
}

/**
   The size of the deque.
**/
long df_size(dequef *D)
{
   return D->size;
}

/**
   Add x to the end of D.

   If the array is full, it first tries to increase the array size to
   capacity*factor.

   On success it returns 1.
   If attempting to resize the array fails then it returns 0 and D remains unchanged.
**/
int df_push(dequef *D, float x)
{
   int pos;

   if (D->size == D->cap)
   {

      int newSize = (D->cap * D->factor);
      float *resize = malloc(sizeof(float) * (newSize));
      if (resize)
      {

         for (int i = 0, pos = D->first; i < D->size; i++, pos++)
         {
            if (pos == D->cap)
            {
               pos = 0;
            }
            resize[i] = D->data[pos];
         }

         D->cap = newSize;
         D->first = 0;
         free(D->data);
         D->data = resize;
      }
      else
      {
         return 0;
      }
   }

   pos = (D->first + D->size) % (D->cap);
   D->data[pos] = x;
   D->size++;

   return 1;
}

/**
   Remove a float from the end of D.

   If the deque has capacity/(factor^2) it tries to reduce the array size to
   capacity/factor.  If capacity/factor is smaller than the minimum capacity,
   the minimum capacity is used instead.  If it is not possible to resize, then
   the array size remains unchanged.

   This function returns the float removed from D.
   If D was empty prior to invocation, it returns 0.0 and D remains unchanged.
**/
float df_pop(dequef *D)
{
   int pos;

   long numOfElementsToShrink = (long)D->cap / (pow(D->factor, 2));
   long shrinkSize = (long)(D->cap / D->factor);

   if (D->size == numOfElementsToShrink && shrinkSize >= D->mincap)
   {

      float *resize = malloc(sizeof(float) * (shrinkSize));
      if (resize)
      {
         for (int i = 0, pos = D->first; i < D->size; i++, pos++)
         {
            if (pos == D->cap)
            {
               pos = 0;
            }
            resize[i] = D->data[pos];
         }
         D->cap = shrinkSize;
         D->first = 0;
         free(D->data);
         D->data = resize;
      }
      else
      {
         return 0.0;
      }
   }

   D->size--;

   pos = (D->first + D->size) % (D->cap);

   if (D->size == 0)
   {
      D->first = 0;
   }

   return D->data[pos];
}

/**
   Add x to the beginning of D.

   If the array is full, it first tries to increase the array size to
   capacity*factor.

   On success it returns 1.
   If attempting to resize the array fails then it returns 0 and D remains unchanged.
**/
int df_inject(dequef *D, float x)
{

   int pos;

   if (D->size == D->cap)
   {

      int newSize = (D->cap * D->factor);
      float *resize = malloc(sizeof(float) * (newSize));
      if (resize)
      {

         for (int i = 0, pos = D->first; i < D->size; i++, pos++)
         {
            if (pos == D->cap)
            {
               pos = 0;
            }
            resize[i] = D->data[pos];
         }

         D->cap = newSize;
         D->first = 0;
         free(D->data);
         D->data = resize;
      }
      else
      {
         return 0;
      }
   }

   if (D->first == 0)
   {
      D->first = D->cap;
   }

   D->first--;
   pos = D->first;
   D->data[pos] = x;
   D->size++;

   return 1;
}

/**
   Remove a float from the beginning of D.

   If the deque has capacity/(factor^2) elements, this function tries to reduce
   the array size to capacity/factor.  If capacity/factor is smaller than the
   minimum capacity, the minimum capacity is used instead.

   If it is not possible to resize, then the array size remains unchanged.

   This function returns the float removed from D.
   If D was empty prior to invocation, it returns 0.0 and D remains unchanged.
**/
float df_eject(dequef *D)
{
   int pos;

   long numOfElementsToShrink = (long)D->cap / (pow(D->factor, 2));
   long shrinkSize = (long)(D->cap / D->factor);

   if (D->size == numOfElementsToShrink && shrinkSize >= D->mincap)
   {

      float *resize = malloc(sizeof(float) * (shrinkSize));
      if (resize)
      {
         for (int i = 0, pos = D->first; i < D->size; i++, pos++)
         {
            if (pos == D->cap)
            {
               pos = 0;
            }
            resize[i] = D->data[pos];
         }
         D->cap = shrinkSize;
         D->first = 0;
         free(D->data);
         D->data = resize;
      }
      else
      {
         return 0.0;
      }
   }

   pos = D->first;
   D->size--;
   D->first++;
   if (D->first == D->cap)
   {
      D->first = 0;
   }

   return D->data[pos];
}

/**
   Set D[i] to x.

   If i is not in [0,|D|-1]] then D remains unchanged.
**/
void df_set(dequef *D, long i, float x)
{

   if (i >= 0 && i < D->cap)
      D->data[(i + D->first) % D->cap] = x;
}

/**
   Return D[i].

   If i is not in [0,|D|-1]] it returns 0.0.
**/
float df_get(dequef *D, long i)
{
   if (i >= 0 && i < D->cap)
      return D->data[(i + D->first) % D->cap];
   return 0.0;
}

/**
   Print the elements of D in a line.0
**/
void df_print(dequef *D)
{
   printf("deque (%ld): ", D->size);
   for (int i = 0, j = D->first; i < D->size; i++, j++)
   {
      if (j == D->cap)
      {
         j = 0;
      }
      printf("%.1f ", D->data[j]);
   }
   printf("\n");
}
