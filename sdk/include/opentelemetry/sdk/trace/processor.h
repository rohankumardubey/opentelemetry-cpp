#pragma once

#include <chrono>
#include <memory>
#include "opentelemetry/sdk/trace/recordable.h"

OPENTELEMETRY_BEGIN_NAMESPACE
namespace sdk
{
namespace trace
{
/**
 * Span processor allow hooks for span start and end method invocations.
 *
 * Built-in span processors are responsible for batching and conversion of
 * spans to exportable representation and passing batches to exporters.
 */
class SpanProcessor
{
public:
  virtual ~SpanProcessor() = default;

  /**
   * Create a span recordable. This requests a new span recordable from the
   * associated exporter.
   * @return a newly initialized recordable
   */
  virtual std::unique_ptr<Recordable> MakeRecordable() noexcept = 0;

  /**
   * OnStart is called when a span is started.
   * @param span a recordable for a span that was just started
   */
  virtual void OnStart(Recordable &span) noexcept = 0;

  /**
   * OnEnd is called when a span is ended.
   * @param span a recordable for a span that was ended
   */
  virtual void OnEnd(std::unique_ptr<Recordable> &&span) noexcept = 0;

  /**
   * Export all ended spans that have not yet been exported.
   * @param timeout an optional timeout, the default timeout of 0 means that no
   * timeout is applied.
   */
  virtual void ForceFlush(
      std::chrono::microseconds timeout = std::chrono::microseconds(0)) noexcept = 0;

  /**
   * Shut down the processor and do any cleanup required. Ended spans are
   * exported before shutdown. After the call to Shutdown, subsequent calls to
   * OnStart, OnEnd, ForceFlush or Shutdown will return immediately without
   * doing anything.
   * @param timeout an optional timeout, the default timeout of 0 means that no
   * timeout is applied.
   */
  virtual void Shutdown(
      std::chrono::microseconds timeout = std::chrono::microseconds(0)) noexcept = 0;
};
}  // namespace trace
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE