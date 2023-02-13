#ifndef MACROS_H_
#define MACROS_H_

#define HighBit(adress, bit) (adress |= (1 << bit)) //make output
#define LowBit(adress, bit) (adress &= ~(1 << bit)) //make input
#define GetBit(adress, bit) (adress & (1 << bit))
#define ChangeBit(adress, bit) (adress ^ (1 << bit))

#endif /* MACROS_H_ */