F405_TARGETS    += $(TARGET)
FEATURES        += VCP  SDCARD_SPI

TARGET_SRC = \
            drivers/barometer/barometer_bmp085.c \
            drivers/barometer/barometer_bmp280.c \
            drivers/barometer/barometer_ms5611.c \
            drivers/barometer/barometer_dps310.c \
            drivers/compass/compass_ak8975.c \
            drivers/compass/compass_hmc5883l.c \
            drivers/compass/compass_qmc5883l.c \
            drivers/compass/compass_lis3mdl.c \
            drivers/accgyro/accgyro_mpu.c \
            drivers/accgyro/accgyro_spi_icm426xx.c \
            drivers/max7456.c
            
          
            