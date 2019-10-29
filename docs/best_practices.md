# Best Practices

## Namespaced Prefix

All machine names coming from the original SiteFarm Seed use the `sf_` prefix.

All new machine names (for content types, views, image styles, etc...) should be
prefixed with an appropriate namespace such as `ucla_`. This ensures that there
are no conflicts with future updates or customizations made by end users.

It also allows those items to be locked down so that they can not be altered by
end users. This is achieved by adding that prefix to the
`lock_sitefarm_features.settings.yml` config file.

## Composer

Composer should ony be run from the distribution's root directory. Never run
composer in a module or profile. This will try to download dependencies and
modules into that module or profile. In the case of a profile, it will actually
download a copy of Drupal Core into the profile. So. Only run composer in the
distribution's root directory.

Commit the `composer.lock` file in the distributions root directory. This will
ensure that everyone gets the exact same modules and php packages every time
they do a `$ composer install`.

### Updating modules
When updating modules, it is best to do one module at a time rather than doing
a wholesale `$ composer update`. So to update the metatag module just run
`$ composer update drupal/metatag`. If a module or php package has dependencies
that need updating as well, add the `--with-dependencies` parameter.

## Drupal Console

Use [Drupal Console](https://drupalconsole.com/) for generating code for
everything from modules to themes.

It is also useful for finding available services when doing dependency injection
into classes. From the Drupal root `docroot` directory run:

```
$ ../vendor/bin/drupal container:debug
```
## Overriding Services

SiteFarm Seed provides several Services which can be overridden. This is useful
especially for services used in procedural hooks within areas like the
`sitefarm_core.module` file.

By moving all the code in hooks into services it is possible to swap out the
service with one of your own. This means that everything inside a `.module`
file can be undone if needed.

This can be more useful than simply turning off a module or overriding it.
The base class can be extended and then only the methods that need to be changed
can be overridden. This way changes can be more surgical, and the original code
can still be used when desired.

https://api.drupal.org/api/drupal/core!core.api.php/group/container/8.8.x#sec_injection

## Style switching with Block Style Plugins

The [Block Style Plugins](https://www.drupal.org/project/block_style_plugins)
module is designed to allow day-to-day editors the ability to swap styles per
block. A themer can designate which styles apply to which blocks. This keeps
style and data separate so that a theme can be switched and offer its own
styles.

Documentation: [https://www.drupal.org/docs/8/modules/block-style-plugins](https://www.drupal.org/docs/8/modules/block-style-plugins)

## Testing

Always test out new configuration by creating a brand new site installation. To
speed this along you can use docksal. From the root directory run:

```
$ fin reinstall
```

This will reinstall just the Drupal site without touching any files.

### Testing updates to existing sites
Before you start adding new features, create a database backup first so that it
can be used for testing later. It is helpful to have an older database backup of
a fresh install. This way it is easier to see if the most recent changes take
place without the cruft of a live site's backup. So before you start adding new
features, create a database backup of a fresh install first. Run Behat tests.

Load in a database backup of an existing site and run updates with
`fin drush updb`. Then look to see that all config updates have applied and then
run Behat tests.

### Behavioral Testing with Behat
It is recommended to write a Behat tests to verify that the desired effects from
a configuration change have applied correctly.

### Unit tests with PHPUnit
Every public method in a PHP class or Service should have a unit test to ensure
that it works properly
