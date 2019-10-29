# Behat Testing for SiteFarm Seed

General Behat documentation can be found at [http://behat.org/en/latest/guides.html](http://behat.org/en/latest/guides.html).

## Running behat


All behat tests are found at `/docroot/profiles/sitefarm_seed/tests/`. Run tests
from any directory with:

```
$ fin behat
```

### Run a specific test
Specify a specific test by adding the `@local` tag to a test:
```
$ fin bhl
```

### Run only tests in a specific file
Specify a specific test "feature" filename:
```
$ fin behat /docroot/profiles/sitefarm_seed/tests/features/featurename.feature
```

### Grouping with Tags
Behat tests can be tagged into groups. Tags affect what options from the config
file are in effect. You can also use tags to run only a subset of the available
tests.

For example, to include only tests that are tagged as 'javascript':
```
$ fin behat --tags=javascript
```

To exclude tests that are tagged as 'javascript':
```
$ fin behat --tags=~javascript
```

`@api` - Any test that requires anything more than blackbox access (for example,
any test that starts by creating a user and logging them in) should be tagged
with `@api` so it can use drush or get direct access to internal Drupal
functions.

`@javascript` - Any test that requires browser interaction (for example,
WYSIWYG editing or other Javascript functions) should be tagged with
`@javascript`.

# PHPUnit for Unit tests

PHPUnit is used for unit testing each class. Unit tests ensure that each class
and method does exactly what it is meant to do.

General PHPUnit documentation can be found at
[https://phpunit.de/documentation.html](https://phpunit.de/documentation.html).

Drupal specific PHPUnit testing documentation can be found at
[https://www.drupal.org/docs/8/phpunit](https://www.drupal.org/docs/8/phpunit).

## Running PHPUnit

> *** UNDER DEVELOPMENT ***

PHPUnit tests need to be run from sitefarm_seed profile directory:
```
$ cd /docroot/profiles/sitefarm_seed
```
Then run all unit tests in the sitefarm_seed profile

```
$ /path/to/MYPROJECT/vendor/bin/phpunit
```
or from inside the profile:
```
$ ../../../vendor/bin/phpunit
```

### Run only tests in a specific group
Groups in PHPUnit are specified by a `@group` Annotation. For example, to run all of the "sitefarm_core" tests:
```
$ /path/to/MYPROJECT/vendor/bin/phpunit --group sitefarm_core
```
