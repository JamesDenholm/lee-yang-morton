/* vim: set et sts=4 sw=4 cc=80 tw=80: */

/*******************************************
 *
 *          File header goes here?
 *              In theory?
 *
 *******************************************/

typedef struct bitseq_s
{
    unsigned int    length;     // In bits
    unsigned int    alloc_size; // In bytes
    unsigned char*  seq;
} bitseq;

bitseq* new_bitseq();

void insert_bit(bitseq*, unsigned int, unsigned char);
void append_bit(bitseq*, unsigned char);

unsigned char get_bit(bitseq*, unsigned int);

bitseq* weave_bits(void*, void*, unsigned int);
bitseq* weave_ints(int, int);
bitseq* weave_uints(unsigned int, unsigned int);

long unsigned int get_as_luint_ljust(bitseq*);
long unsigned int get_as_luint_rjust(bitseq*);
unsigned int get_as_uint_ljust(bitseq*);
unsigned int get_as_uint_rjust(bitseq*);

void pprint_bitseq(bitseq*);


unsigned char get_bit_void_ptr(void*, unsigned int);
void htobe(void*, unsigned int);
