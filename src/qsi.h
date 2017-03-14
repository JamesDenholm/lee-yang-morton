/* vim: set et sts=4 sw=4 cc=80 tw=80: */

/*******************************************
 *
 *          File header goes here?
 *              In theory?
 *
 *******************************************/

#ifndef QSI_H
#define QSI_H

#include "bitseq.h"

/* psum: Partial sum. Which is, fundamentally, what this structure
 * is used for: Partial sums of the unary-encoded array.
 */
typedef struct qsipsum_s
{
    /* I think luint sum is justified due to it being used in the Lee-Yang
     * implementation, which uses luints for the Morton codes (ergo, sum needs
     * to potentially go up to luint max).
     *
     * luint index is there for consistency and because I think bitseq->length
     * might need to move from uint to luint lengths at some point anyway.
     */
    long unsigned int   index;  // Index of the bit from which to read *from*.
                                // Ergo, works with read_unary_as_uint()
    long unsigned int   sum;
} qsipsum;

/* By having a list of partial sums, we can use partial sums as a skip-ahead
 * method.
 */
typedef struct qsipsums_s
{
    long unsigned int   len;
    long unsigned int   size;
    qsipsum*            psums;
} qsipsums;

typedef struct qsiseq_s
{
    bitseq*             hi; // High-bits sequence
    bitseq*             lo; // Low-bits sequence
    long unsigned int   u;  // Upper bound
    long unsigned int   n;  // (Expected) number of elements
    long unsigned int   len;// Current number of elements

    unsigned int        q;  // "Quantum" for hi_psums
    qsipsums*           hi_psums;   // Partial sums array for high-bit seq.
} qsiseq;

qsiseq* new_qsiseq();

void qsi_set_u(qsiseq*, long unsigned int);
void qsi_set_n(qsiseq*, long unsigned int);
unsigned int qsi_lowbit_length(qsiseq*);

long unsigned int qsi_get_upper(qsiseq*, long unsigned int);
long unsigned int qsi_get_final_upper(qsiseq*);

void qsi_append(qsiseq*, long unsigned int);
void qsi_append_psum(qsiseq*, long unsigned int, long unsigned int);

void qsi_update_psums(qsiseq*);

void pprint_qsiseq(qsiseq*);

#endif /* QSI_H */