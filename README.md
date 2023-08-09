# Simple C++ wrapper for Github REST API

C++ library to interact with github.com REST API

## Supported endpoints

Api reference: https://docs.github.com/en/rest?apiVersion=2022-11-28

* Commits
  * Commits
    * [List pull requests associated with a commit](https://docs.github.com/en/rest/commits/commits?apiVersion=2022-11-28#list-pull-requests-associated-with-a-commit)
* Git Database
  * Commits
    * [Create a commit](https://docs.github.com/en/rest/git/commits?apiVersion=2022-11-28#create-a-commit)
    * [Get a commit object](https://docs.github.com/en/rest/git/commits?apiVersion=2022-11-28#get-a-commit-object)
  * References
    * [Get a reference](https://docs.github.com/en/rest/git/refs?apiVersion=2022-11-28#get-a-reference)
    * [Create a reference](https://docs.github.com/en/rest/git/refs?apiVersion=2022-11-28#create-a-reference)
    * [Update a reference](https://docs.github.com/en/rest/git/refs?apiVersion=2022-11-28#update-a-reference)
  * Trees
    * [Create a tree](https://docs.github.com/en/rest/git/trees?apiVersion=2022-11-28#create-a-tree)
* Pulls
  * Pulls
    * [Get a pull request](https://docs.github.com/en/rest/pulls/pulls?apiVersion=2022-11-28#get-a-pull-request)
    * [Update a pull request](https://docs.github.com/en/rest/pulls/pulls?apiVersion=2022-11-28#update-a-pull-request)
* Repositories
  * Contents
    * [Get repository content](https://docs.github.com/en/rest/repos/contents?apiVersion=2022-11-28#get-repository-content)

## Build prerequisites

* Linux:
  libssl-dev

