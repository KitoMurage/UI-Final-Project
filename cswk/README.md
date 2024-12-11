# Project Title: COMP2811 UI Final Project Coursework

- **Team Members**:
    - Shaikha Mohamed Al Slais - Student ID: 201659913
    - Juri Hamed Alsubhi - Student ID: 201778857
    - Kito Murage Magu - Student ID: 201739649

- **Project Overview**:
    This application, built using Qt, is designed to monitor and track UK and EU water quality data. It provides data visualization through charts, making it easier to understand trends and patterns. Users can filter specific pollutants and evaluate their safety levels, as well as filter data by location to assess compliance with regulations.

- **Setup Instructions**:
    1. **Extract the Starter Code**: 
        - Unzip the provided starter code package to a working directory.
    2. **Build the Project**:
        - Create a `build` directory and run `cmake`:
        ```bash
        mkdir build && cd build
        cmake ..
        ```
        - Compile the project:
        ```bash
        make
        ```
        - Run the application:
      ```bash
      ./[application-executable-name]
      ```

- **File Structure**:
    - **Folders**:
        - **data** - Contains 5 CSV files with water quality data from Yorkshire, spanning the years 2020 to 2024. These files can be selected to load data into the application.
        - **translation** - Includes .ts and .qm files for language support (Spanish, English (GB), and English (US)). These files enable the application to change languages based on the user's system settings.

    - **Main Files**:
        - **main.cpp**: The entry point of the application, responsible for running the program.
        - **CMakeLists.txt**: The build configuration file for compiling the application.

     - **Page Files**: - Includes all .cpp and .hpp files for the dashboard, overview, POP, dataset, pollutant, model, and window components.
