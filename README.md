# Viral Simulation Assignment

This code runs a simplistic simulation of a population which can be infected with a virus that spreads between humans. The representation of this population is a cloud of dots, with each dot being a human and called a 'subject' in the simulation. This project is used as the basis for the new assignment that replaces the test for Object Oriented Programming 2. The simulation is written in C++ and is compiled to WebAssembly by using the Emscripten compiler. WebAssembly has gained more traction in recent times, which makes this a good time to learn about and get experience with it. The assignment, instructions and resources follow below.

## **Assignment**

This assignment will rely on knowledge about C++ and also the skills to implement programs with it, as a regular test would also have done. The knowledge segment of the assignment will come into play whilst you get the project running on your computer because you have to work with a different compiler (EMCC) and build system (Make). Implementing the program will be done by adding onto the existing program given in this repository.

The assignment is split up in two parts:

### _**A.**_ Generic assignment - Strategy Pattern

Simulate social distancing by having 75% of all subjects in the simulation stand still. Do this by changing the code of the subjects so that the way in which subjects move is governed by a strategy, by implementing the strategy pattern. This is done to have one generic class Subject instead of multiple variants of subjects. Design the code according to the video given in the sources at the end of this document, so that it results in `RegularMovementStrategy` and  `LockdownMovementStrategy` classes which both implement a `MovementStrategy` interface.

### _**B.**_ Student number dependent assignment

The specific assignment you have to fulfill here depends on your student number. You can check which assignment you have to do by loading `assignment_checker.html` and filling in your student number. You can find the possible assignments below.

#### _**B.1**_ Lockdown

Simulate a state of lockdown by imposing restrictions on subject movement once half of the subject population gets infected (100 subjects). The movement restrictions will be simulated by having 75% of the subjects starting to move very slowly. Which subjects move slowly and which do not should be decided at random.

#### _**B.2**_ Exit Strategy

Lockdowns impose restrictions which eventually have to be lifted. Sometimes this causes a second wave of infections. Simulate such a wave by having groups of subjects spread out over the simulated area where the subjects barely move. Code your simulation so that as time progresses, the subjects start to move more and more untill they move normally again.

#### _**B.3**_ Getting better

Simulate a situation in which subjects can get better again after a certain period of time and are then periodically immune to the virus. You are free to choose these durations yourself. Once a subject is not immune anymore, it can be infected again. Do this by adding the option of immunity to the subjects.

## **Instructions**

This assignment has to be completed individually and will be graded digitally. To aid in this process, you will not just upload the source code. Instead, you are required to clone this GitHub repository into your own account, modify it as needed for completing the assignment and committing these changes to your repository, and handing in the link to that repository. This allows us to review your commit history which gives us a good indication of your development process. The location for handing in the link to your repository, as well as the rubric used for grading the assignment, will be communicated with you through your academic email.

To start this project, two options are available. It can be installed on a local system, but it is also available on OpenShift.io (a cloud IDE).

1. **OpenShift.io**<br/>
OpenShift.io is a free service which let's you develop in a remote Linux environment for free (certain quota apply). To start with OpenShift.io, you need an account with the service. This can be made through [OpenShift.io](https://openshift.io/), by clicking on **SIGN UP**. It is advised to use your GitHub account, because the standard RedHat account does not provide facilities for 2-factor authentication.<br/><br/>
When signed up, your account will be provisioned to receive a free workspace. This workspace has to be configured before it can be used. A number of templates are available, but we will be using a custom configuration file. In the workspaces tab, click on *Add Workspace*. In the following form, you will see a text box showing *URL or devfile*. In this text box, you can paste the following URL: https://raw.githubusercontent.com/wbrinksma/Viral-Simulation-2020-2021/main/devfile.yaml. Then, click on *Load devfile*. This will load the specified configuration from this repository. Once done, scroll to the bottom of the page and click **Create & Open**. This will start the workspace and configure it accordingly. You will be presented with the code and a familiar development environment. One manual configration step is needed however. Click on the file *Makefile*, and edit line 3 to show PATH_TO_EMCC=emcc (and ofcourse, save the file afterwards). To run the code, click on the tab *Terminal* and then *Run Task...*. Choose *run-production* from the dropdown menu, and the build and run process will commence. This will run a small server on port 8000, which is exposed in your configuration. The development environment will detect this, and display a message in the bottom right corner to ask if you want to view the content from the started server. Opening it in a new window will use a pop-up, which can be blocked by your browser. Opening it in preview will show a small screen next to the editor which will preview your application. To close the application, you can click the terminal the *run-production* is running in (bottom of the page) and press ctrl-c. This will stop the server by making the process exit.<br/><br/>
Below, you will find some resources important to the project.

2. **Local installation**<br/>
To start this project on a local machine, you will need a few dependencies installed on your system:<br/>
- Git
- Python3
- Emscripten compiler (EMCC)
- Make
- Editor of your choice (Visual Studio Code recommended)<br/><br/>
Below, you will find resources to get these things running and recommendations on which system to use.

## **Guide and resources**

This project is compiled to WebAssembly. The compiler we use is called Emscripten, and is used because of the extensive support it has for building WebAssembly that can interface with the HTML page in the browser. Installing and running this is easiest on Linux systems, though can be done on Windows and MacOS based devices too. If you are on windows, **it is strongly advised to use the _Windows subsystem for Linux_ environment**. This makes setting up the environment a lot more easy. The compiler is invoked by a `Makefile`, which is a file that contains commands to automatically build the project. You can however still use the command line to build the project too, by invoking the command which is labeled as _build_. Make, the program which manages the build process, is available for Linux, Windows and MacOS. Again, on Linux the execution is easiest.

To run this project, you should review and understand the given Makefile. You can do this by reading the make tutorial provided below. The file consists of variables, labels and commands to be executed by the computer once it needs to build the software. The first portion of the file is filled with variables. These are used to make editing the file easier. The variables contain paths that are needed to get the right files and to know where to put the output of the compiler. There is also the variable `PATH_TO_EMCC`. This variable should be changed by you to the appropriate path on your computer. This is the only variable that needs to be changed to get the project working on your computer. Also, when you add header or source files to the project, you should add these files to the `HEADER_FILES` and `SOURCE_FILES` respectively. These lists of files are used in the build process by make and the compiler, so they need to be added or the project will not compile correctly. Below the variables are labels for different operations make can perform on this project. You can view them as functions which can be individually executed. Some of these functions are executed together. The two labels that are important for us are `run-debug` and `run-production`. You can invoke them with the make command by typing in your terminal `make run-debug` and `make run-production`. These commands will then first clean your build directory, copy dependencies into it, compile your C++ code to WebAssembly and run a small Python-powered web server to test your code.

The code is built up in such a way that the main portion is platform independent. Almost all the C++ code will compile for a regular build target like a Windows or Linux executable. Only the classes `HTMLCanvas` and `ChartJSHandler` are different in that they use specific Emscripten functions to communicate with the browser. If you need this code to run elsewhere, it is very simple now to do so by just re-implementing these classes. (Simulation also contains a reference to Emscripten, which is done to let the simulation sleep to achieve 30 frames per second.) These classes do not have to be changed.

Material you will need to review is listed below.

- [WebAssembly](https://webassembly.org/) (Short read)
- [Emscripten](https://emscripten.org/) (Medium read + tutorial to install)
- [Windows subsystem for Linux](https://docs.microsoft.com/en-us/windows/wsl/install-win10) (Small tutorial)
- [Make tutorial](http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/) (Short read)
- [Strategy pattern](https://www.youtube.com/watch?v=sRuem-JQZRE) (Short video)
