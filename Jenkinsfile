pipeline {
    agent any
    environment {
        PROJECT_NAME = "Minishell1"
        BINARY_NAME = "mysh"
        TEST_REPO = "https://github.com/Epitests-unofficial/B-PSU-200-Minishell1.git"
    }
    stages {
        stage ("Code Style (marvin only)") {
            steps {
                sh "python3 /usr/local/lib/abricot/__main__.py --format plain --status --group file --ignore"
            }
        }
        stage ("Code Style (all)") {
            steps {
                sh "python3 /usr/local/lib/abricot/__main__.py --all --format plain --group file --ignore"
            }
        }
        stage ("Building") {
            agent {
                docker {
                    image "epitechcontent/epitest-docker"                    
                }
            }
            steps {
                sh "make re"
                sh "test -f $BINARY_NAME"
            }
        }
        stage ("Criterion Tests") {
            agent {
                docker { image "epitechcontent/epitest-docker" }
            }
            steps {
                sh "if [ \$(cat Makefile | grep tests_run: | wc -l) > 0 ]; then if make tests_run 2>&1 | grep 'FAIL\\|Error 1'; then exit 1; else exit 0; fi; else: echo 'No Criterion Tests'; fi"
            }
        }
        stage ("Bash Tests (external repo)") {
            agent {
                docker { image "epitechcontent/epitest-docker" }
            }
            steps {
                sh "git clone $TEST_REPO /tmp/tests"
                sh "make -C /tmp/tests"
                sh "if ! test -f /tmp/tests/tester.sh; then echo 'No Bash test file'; exit 0; fi"
                sh "mv $BINARY_NAME /tmp/tests/$BINARY_NAME"
                sh "cd /tmp/tests"
                sh "chmod +x tester.sh"
                sh "./tester.sh"
            }
        }
    }

    post {
        always {
            emailext subject: '$PROJECT_NAME - Build # $BUILD_NUMBER - $BUILD_STATUS!',
            body: '${SCRIPT, template="groovy-html.template"}',
            recipientProviders: [[$class: 'DevelopersRecipientProvider'],
            [$class: 'RequesterRecipientProvider']],
            attachLog: true,
            from: 'autotest@mail.jenkins.nicojqn.fr'
        }
    }
}