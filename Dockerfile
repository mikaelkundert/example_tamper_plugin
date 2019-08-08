FROM drupal:7

RUN apt-get update \
    && apt-get install -y git

RUN cd sites/all/modules \
    && git clone --branch 7.x-1.x https://git.drupalcode.org/project/ctools.git \
    && cd ctools && git checkout f2177195c92b53719402da69b03a731ba25020dc && cd .. \
    && git clone --branch 7.x-2.x https://git.drupalcode.org/project/job_scheduler.git \
    && cd job_scheduler && git checkout 75b7f4ece135bdde962ad0a0a8f8b6373b2afd8f && cd .. \
    && git clone --branch 7.x-2.x https://git.drupalcode.org/project/feeds.git \
    && cd feeds && git checkout b39b547768abbda3b0d7b5425593c0e7c05800f2 && cd ..  \
    && git clone --branch 7.x-1.x https://git.drupalcode.org/project/feeds_tamper.git \
    && cd feeds_tamper && git checkout 49ea6f9895eb05e31b0c3bc1aebdc4419415661f && cd ..  \
    && git clone --branch master https://github.com/mikaelkundert/example_tamper_plugin.git
