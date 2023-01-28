/*
 * I2C_Config.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_I2C_I2C_CONFIG_H_
#define MCAL_I2C_I2C_CONFIG_H_

/*
 * SELECT I2C_MODE OPTIONS -> [ I2C_MASTER , I2C_SLAVE ]
 */
#define I2C_MODE                     I2C_MASTER
/*
 * SELECT I2C_SLAVE_ADDRESS RANGE -> [ 1 TO 119 ]
 */
#define I2C_SLAVE_ADDRESS             1
/*
 * I2C_GENERAL_CALL OPTIONS ->  0 (DEISABLE)
 *                              1 (ENABLE)
 */
#define I2C_GENERAL_CALL              0

#endif /* MCAL_I2C_I2C_CONFIG_H_ */
