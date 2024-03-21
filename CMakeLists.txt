cmake_minimum_required(VERSION 3.27)
project(Test)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp Appointment.cpp DentistManager.cpp AppointmentDisplay.cpp AppointmentManager.cpp Patient.cpp Person.cpp CSVSearcher.cpp DateTimeUtils.cpp Dentist.cpp)

add_executable(Test ${SOURCE_FILES})
