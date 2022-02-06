cmake_minimum_required(VERSION 3.21)
project(src)

set(CMAKE_CXX_STANDARD 14)

add_executable(src
        main.cpp
        colloid.cpp
        colloid.h
        colloidparticle.cpp
        colloidparticle.h
        computemethod.cpp
        computemethod.h
        dipole.cpp
        dipole.h
        environment.cpp
        environment.h
        field.cpp
        field.h
        macroparticle.cpp
        macroparticle.h
        material.cpp
        material.h
        maths.cpp
        maths.h
        particle.cpp
        particle.h
        particlesystem.cpp
        particlesystem.h
        print.h
        rotatingfield.cpp
        rotatingfield.h
        runmanager.cpp
        runmanager.h
        selfconsistentmethod.cpp
        selfconsistentmethod.h
        shape.cpp
        shape.h
        staticfield.cpp
        staticfield.h
        )
