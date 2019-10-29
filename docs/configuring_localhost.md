# Configuring Your Localhost

## Step 1: Install Docksal

Install and enable [Docksal](https://docksal.io)

## Step 2: Get SiteDen Distribution

Clone the [siteden-acquia](https://bitbucket.org/siteden/siteden-acquia) onto your local environment. The root directory will be `siteden-acquia`, which is what will be referenced in the rest of this document. 

## Step 3: Configure Your Local Host

Open your CLI of choice and navigate to the `siteden-acquia` directory. Run:

```
$ fin init
```

The script will install the site, compile css and js, and then at the end
provide you with a login link.

You're done!

## Helpful Docksal Commands

* Get a list of commands available in Docksal:
    * `$ fin help`
* Installation commands
    * `$ fin init` Initial installation of all dependencies and compiles assets.
    * `$ fin reinstall` Do a fresh Drupal installation of the SiteDen profile. Be sure to have xDebug disabled.
* Theme commands
    * `$ fin theme-build` Compile theme assets from source files.
    * `$ fin theme-install` Install theme npm dependencies.
    * `$ fin theme-sync` Synchronize the master branch of Pattern Lab to the theme.
    * `$ fin theme-watch` Compile theme assets and watch for changes.
* Testing commands
    * `$ fin behat` Run project's Behat tests.
    * `$ fin bhl` Runs behat on only `@local` tagged items.
    * `$ fin phpunit` Run project's PHPUnit tests.
* Use “Drush” from the root directory with:
    * `$ fin drush`
* Log in as an Administrator:
    * `$ fin drush uli`
    * copy the url after `http://default/` and paste it after your local host name in the browser
* Use “Composer”:
    * `$ fin composer`
