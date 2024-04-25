cmake_minimum_required(VERSION 3.27)
project(Run)

set(CMAKE_CXX_STANDARD 17)

# Define the source files for each program
set(Dentist_Programme_SOURCES Dentist_Programme.cpp Print_Functions.h Person.cpp Person.h Dentist.cpp Dentist.h Patient.cpp Patient.h Appointment.cpp Appointment.h Room.cpp Room.h Data.cpp Data.cpp CSV_Reader.cpp CSV_Reader.h Interface.cpp Interface.h View.cpp View.h Calendar.cpp Calendar.h Input_Validation.cpp Input_Validation.h Book.cpp Book.h QuickSort.cpp QuickSort.h PatientManager.cpp PatientManager.h
        Book.cpp
        Book.h
        CSVSearcher.cpp
        CSVSearcher.h
        DateTimeUtils.cpp
        DateTimeUtils.h
        DentistManager.cpp
        DentistManager.h
        AppointmentDisplay.cpp
        AppointmentDisplay.cpp)
set(Quicksort_Test_SOURCES main.cpp Person.cpp Person.h Dentist.cpp Dentist.h Patient.cpp Patient.h Appointment.cpp Appointment.h QuickSort.cpp QuickSort.h )
set(Testing_Programme_SOURCES Testing_File.cpp catch.hpp Print_Functions.h Person.cpp Person.h Dentist.cpp Dentist.h Patient.cpp Patient.h Appointment.cpp Appointment.h Room.cpp Room.h Data.cpp Data.h)

# Define the executable for the first program
add_executable(Dentist_Programme ${Dentist_Programme_SOURCES})
# Define the executable for the second program
add_executable(Quicksort_Test ${Quicksort_Test_SOURCES})
# Define the executable for the third program
add_executable(Testing_Programme ${Testing_Programme_SOURCES})
