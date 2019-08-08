# Example Tamper Plugin

This repository contains example code for writing a custom Feeds
Tamper Plugin.

This repository is created for recovering an old blog post from year 2011. Note
that some of depency modules might have known vulnerabilities. Run this only on
testing purposes!

## Running on Docker

```
$ wget https://github.com/mikaelkundert/example_tamper_plugin/archive/master.zip
$ unzip master.zip -d example_tamper_plugin
$ cd example_tamper_plugin
$ docker build -t example_tamper_plugin .
$ docker run example_tamper_plugin
```
