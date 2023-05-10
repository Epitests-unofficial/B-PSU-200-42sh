# B-PSU-200-42sh - Unit Tests

Any tests for 42sh Epitech Project

These tests are written in bash thanks to the epitech original tester.tgz


#### Tests Running

* Clone this repo
* `make`
* Copy your `mysh` binary at the root of the repo
* run `./tester.sh`

#### Jenkins Pipeline

You can setup a Jenkins pipeline with these tests by this way :

* Download and install [Abricot Norminette](https://https://github.com/Just1truc/Abricot-Norminette) Epitech Coding Style in your Jenkins installation
* Just download the Jenkinsfile (in this repo) and move it at the root of your repo.
* In Jenkins create a new Pipeline and setup with `Pipeline script from SCM` with your personnal repo
* You can set up a Poll SCM settings in build trigger in order to run tests at each update
* Run a first test
