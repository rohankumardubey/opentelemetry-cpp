add_library(
  opentelemetry_metrics
  meter_provider.cc
  meter.cc
  meter_context.cc
  aggregation/histogram_aggregation.cc
  aggregation/lastvalue_aggregation.cc
  aggregation/sum_aggregation.cc
  sync_instruments.cc)

set_target_properties(opentelemetry_metrics PROPERTIES EXPORT_NAME metrics)

target_link_libraries(opentelemetry_metrics PUBLIC opentelemetry_common)

target_include_directories(
  opentelemetry_metrics
  PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/sdk/include>")

install(
  TARGETS opentelemetry_metrics
  EXPORT "${PROJECT_NAME}-target"
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
