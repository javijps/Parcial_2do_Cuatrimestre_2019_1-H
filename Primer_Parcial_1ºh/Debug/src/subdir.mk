################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/auxiliarCliente.c \
../src/cliente.c \
../src/informes.c \
../src/main.c \
../src/pedidoCliente.c \
../src/utn.c 

OBJS += \
./src/auxiliarCliente.o \
./src/cliente.o \
./src/informes.o \
./src/main.o \
./src/pedidoCliente.o \
./src/utn.o 

C_DEPS += \
./src/auxiliarCliente.d \
./src/cliente.d \
./src/informes.d \
./src/main.d \
./src/pedidoCliente.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


