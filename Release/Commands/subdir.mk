################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Commands/FixedCodes.cpp \
../Commands/WriteText.cpp 

OBJS += \
./Commands/FixedCodes.o \
./Commands/WriteText.o 

CPP_DEPS += \
./Commands/FixedCodes.d \
./Commands/WriteText.d 


# Each subdirectory must supply rules for building sources it contributes
Commands/%.o: ../Commands/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O3 -Wall -c -fmessage-length=0 -std=c++11 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


