/*
 * SPI_types.h
 *
 *  Created on: Sep 14, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_SPI_SPI_TYPES_H_
#define SRC_MCAL_SPI_SPI_TYPES_H_

#define SPI_MSB_FIRST                                     0b00100000
#define SPI_LSB_FIRST                                     0b00000000


#define SPI_MASTER                                        0b00010000
#define SPI_SLAVE                                         0b00000000

#define SPI_CLK_POL_RISING                                0b00000000
#define SPI_CLK_POL_FALLING                               0b00001000

#define SPI_CLK_PHA_SETUP_FIRST                           0b00000100
#define SPI_CLK_PHA_SAMPLE_FIRST                          0b00000000

#define SPI_CLK_PRESCALER_4                               0
#define SPI_CLK_PRESCALER_16                              1
#define SPI_CLK_PRESCALER_64                              2
#define SPI_CLK_PRESCALER_128                             3




#endif /* SRC_MCAL_SPI_SPI_TYPES_H_ */
