################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Primer_Parcial_1ºh.c \
../src/clientes.c \
../src/informes.c \
../src/pedidos_de_recoleccion.c \
../src/utn.c 

OBJS += \
./src/Primer_Parcial_1ºh.o \
./src/clientes.o \
./src/informes.o \
./src/pedidos_de_recoleccion.o \
./src/utn.o 

C_DEPS += \
./src/Primer_Parcial_1ºh.d \
./src/clientes.d \
./src/informes.d \
./src/pedidos_de_recoleccion.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


