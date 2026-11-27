# 1. Record architecture decisions

Status: Accepted
Date: 2026-11-27

## Context
Decisions that are costly to reverse get lost in commit messages and chat.

## Decision
Every significant decision gets a numbered ADR in `docs/adr/`, in the format of Michael Nygard:
context, decision, consequences. ADRs are never edited after acceptance; a changed decision
gets a new ADR marked "Supersedes NNNN".

## Consequences
The design doc describes the system as it is now; the ADRs explain how it got there.
