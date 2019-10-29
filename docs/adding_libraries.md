# Adding Third-party libraries via a Sub Profile

Libraries ultimately should go into `/docroot/libraries`. However a profile does not
have access to this directory. Therefore any libraries that need to go there
have to be copied from the profile. A profile should have its own `libraries`
directory that has its content copied into the root `/docroot/libraries`.

A script has been added to `composer.json` of the main distribution that
will copy this directory on install and updates.

```json
"scripts": {
  "post-install-cmd": [
    "cp -a docroot/profiles/sitefarm_seed/libraries/. docroot/libraries/"
  ],
  "post-update-cmd": [
    "cp -a docroot/profiles/sitefarm_seed/libraries/. docroot/libraries/"
  ]
}
```

The previous script will copy libraries from the profile into the main
`/docroot/libraries`.
