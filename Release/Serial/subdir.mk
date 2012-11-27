################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Serial/SerialPort.cpp 

OBJS += \
./Serial/SerialPort.o 

CPP_DEPS += \
./Serial/SerialPort.d 


# Each subdirectory must supply rules for building sources it contributes
Serial/%.o: ../Serial/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


