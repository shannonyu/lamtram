####### Library info

LIBCPP = \
    lamtram-train.cc \
    lamtram.cc \
    ensemble-decoder.cc \
    ensemble-classifier.cc \
    neural-lm.cc \
    linear-encoder.cc \
    encoder-decoder.cc \
    encoder-attentional.cc \
    encoder-classifier.cc \
    timer.cc \
    macros.cc \
    classifier.cc \
    builder-factory.cc \
    model-utils.cc \
    vocabulary.cc

AM_CXXFLAGS = $(BOOST_CPPFLAGS) $(EIGEN_CPPFLAGS) $(CNN_CPPFLAGS) $(OPENMP_CXXFLAGS) -I$(srcdir)/..

lib_LTLIBRARIES = liblamtram.la

liblamtram_la_SOURCES = ${LIBCPP}
liblamtram_la_LDFLAGS = -version-info 0:0:0

####### Binary info

LDADD=liblamtram.la \
    $(CNN_LDFLAGS) \
    $(BOOST_LDFLAGS) \
    $(BOOST_SYSTEM_LIB) \
    $(BOOST_PROGRAM_OPTIONS_LIB) \
    $(BOOST_SERIALIZATION_LIB) \
    $(OPENMP_CXXFLAGS)

bin_PROGRAMS = lamtram-train lamtram

lamtram_train_SOURCES = lamtram-train-main.cc
lamtram_train_LDADD = $(LDADD)

lamtram_SOURCES = lamtram-main.cc
lamtram_LDADD = $(LDADD)