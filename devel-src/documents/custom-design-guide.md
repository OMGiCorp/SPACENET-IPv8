# SPACE*NET Custom Service and Protocol Design Guide

## 1. Design goals

When creating custom SPACE*NET services/protocols:

- Maintain interoperability with IPv4/IPv6 and common transports.
- Keep control plane and data plane separable.
- Specify security model first (authn, authz, integrity, confidentiality).
- Reserve room for future extension in message formats.

## 2. Defining a custom service

Recommended checklist:

1. **Name**: lowercase canonical name (e.g., `spacenet-discovery`).
2. **Port plan**:
   - development/test port in private range.
   - production assignment through internal registry or IANA process.
3. **Transport**: choose TCP/UDP/QUIC by latency/reliability needs.
4. **Wire format**:
   - fixed header + version + flags + length + payload.
   - strict byte order rules (network byte order).
5. **Error model**:
   - explicit status code table.
   - retriable vs terminal error classes.
6. **Operational profile**:
   - timeout policy
   - backoff behavior
   - observability fields (trace-id, node-id).

## 3. Defining a custom protocol number (internal)

For experimental deployments, keep protocol IDs internal and documented:

- Track local assignments in `devel-src/documents/index.dat` using `PROTOCOL|...` format.
- Avoid collision with IANA protocol numbers in global network domains.
- Use encapsulation (GRE/UDP/TCP) if direct protocol number support is limited.

## 4. Security baseline

- Mutual authentication for control channels.
- TLS 1.3 or stronger for user payloads where applicable.
- Replay protection (nonce/window strategy).
- Mandatory audit events for config and policy changes.

## 5. Documentation requirements for each new entry

For every added service/protocol:

- One-line purpose statement.
- Stable identifier (port number or protocol number).
- Reference specification (RFC, draft, or internal spec URL).
- Compatibility notes (legacy stacks, middleboxes, NAT/firewall behavior).

## 6. SPACE*NET extension pattern

Use a vendor-style prefix (`spacenet-*`) and maintain:

- Backward compatibility across minor revisions.
- Feature negotiation in the handshake.
- Capability bitmap for optional modules.

## 7. Suggested future automation

- Generate headers from a single YAML/JSON registry.
- Validate duplicated entries with CI.
- Auto-sync RFC links against RFC Editor metadata APIs.
