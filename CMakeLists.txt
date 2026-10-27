cmake_minimum_required(VERSION 3.16)

project(ProyectoCpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ejercicio 1: Clock
add_library(clock_lib
    ejercicios/clock/clock.cpp
)

target_include_directories(clock_lib PUBLIC
    ejercicios/clock
)

# Ejercicio 2: Meetup
find_package(Boost REQUIRED)

add_library(meetup_lib
    ejercicios/meetup/meetup.cpp
)

target_include_directories(meetup_lib PUBLIC
    ejercicios/meetup
)

target_link_libraries(meetup_lib PUBLIC
    Boost::headers
)

# Ejercicio 3: Underground System
add_library(underground_system_lib
    ejercicios/underground_system/underground_system.cpp
)

# Ejercicio 4: ATM Machine
add_library(atm_machine_lib
    ejercicios/atm_machine/atm_machine.cpp
)

# Ejercicio 5: Auction System
add_library(auction_system_lib
    ejercicios/auction_system/auction_system.cpp
)



