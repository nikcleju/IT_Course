#define READ_BIT(x,i)     ((x) & (1U << (i)))
#define SET_BIT(x,i)      ((x) = (x) | (1U << (i)))
#define CLEAR_BIT(x,i)    ((x) = (x) & ~(1U << (i)))
#define TOGGLE_BIT(x,i)   ((x) = (x) ^ (1U << (i)))
