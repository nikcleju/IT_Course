#define READ_BIT(x,i)       (((x) & (1U << (i))) != 0)
#define SET_BIT(x,i)        ((x) = (x) | (1U << (i)))
#define CLEAR_BIT(x,i)      ((x) = (x) & ~(1U << (i)))
#define TOGGLE_BIT(x,i)     ((x) = (x) ^ (1U << (i)))
#define WRITE_BIT(x,i,val)  ((val) ? SET_BIT((x),(i)) : CLEAR_BIT((x),(i)))

#define VECREAD_BIT(v,i)       (READ_BIT((v[(i)/8]),(i)%8))
#define VECWRITE_BIT(v,i,val)  (WRITE_BIT((v[(i)/8]),(i)%8, val))
