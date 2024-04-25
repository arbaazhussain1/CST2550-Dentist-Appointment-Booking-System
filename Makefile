CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic

all: Dentist_Programme Quicksort_Test Testing_Programme

Dentist_Programme: Dentist_Programme.cpp Print_Functions.h Person.o Dentist.o Patient.o Appointment.o Room.o Data.o CSV_Reader.o Interface.o View.o Calendar.o Input_Validation.o Book.o Quicksort.o PatientManager.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Quicksort_Test: main.cpp Person.o Dentist.o Patient.o Appointment.o Quicksort.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Testing_Programme: Testing_File.cpp catch.hpp Print_Functions.h Person.o Dentist.o Patient.o Appointment.o Room.o Data.o Input_Validation.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Data.o: Data.cpp Data.h
	$(CXX) $(CXXFLAGS) -c $<

CSV_Reader.o: CSV_Reader.cpp CSV_Reader.h
	$(CXX) $(CXXFLAGS) -c $<

Interface.o: Interface.cpp Interface.h
	$(CXX) $(CXXFLAGS) -c $<

View.o: View.cpp View.h
	$(CXX) $(CXXFLAGS) -c $<

Calendar.o: Calendar.cpp Calendar.h
	$(CXX) $(CXXFLAGS) -c $<

Input_Validation.o: Input_Validation.cpp Input_Validation.h
	$(CXX) $(CXXFLAGS) -c $<

Person.o: Person.cpp Person.h
	$(CXX) $(CXXFLAGS) -c $<

Dentist.o: Dentist.cpp Dentist.h
	$(CXX) $(CXXFLAGS) -c $<

Patient.o: Patient.cpp Patient.h
	$(CXX) $(CXXFLAGS) -c $<

Book.o: Book.cpp Book.h
	$(CXX) $(CXXFLAGS) -c $<

Appointment.o: Appointment.cpp Appointment.h
	$(CXX) $(CXXFLAGS) -c $<

Room.o: Room.cpp Room.h
	$(CXX) $(CXXFLAGS) -c $<

Quicksort.o: Quicksort.cpp Quicksort.h
	$(CXX) $(CXXFLAGS) -c $<

PatientManager.o: PatientManager.cpp PatientManager.h
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	$(RM) *.o Dentist_Programme
